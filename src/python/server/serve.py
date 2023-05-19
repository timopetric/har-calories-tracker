import paho.mqtt.client as mqtt
import datetime


topic = "AljazACCData"
FILE_TO_WRITE = f"store.csv"

WRITE_FMT = "{datestr};{wlk};{run};{bik}"


def read_file(file=FILE_TO_WRITE):
    # read file and return list of lines

    with open(file, 'r') as f:
        return [x.strip() for x in f.readlines()]


def write_file(wlk, run, bik, file=FILE_TO_WRITE):
    # write new counters to file or update existing counters by adding new values to them.

    date_str = datetime.datetime.now().strftime("%Y-%m-%d")
    db = read_file()

    # get line inx - line where date is
    line_inx = -1
    for inx, line in enumerate(db):
        if date_str in line:
            line_inx = inx
            break

    if line_inx == -1:
        # create new line entry
        line = WRITE_FMT.format(datestr=date_str, wlk=wlk, run=run, bik=bik)
        db.append(line)
    else:
        # update existing line entry by adding counter values
        line = db[line_inx]
        line = line.split(";")
        wlk = str(int(line[1]) + wlk)
        run = str(int(line[2]) + run)
        bik = str(int(line[3]) + bik)
        line = WRITE_FMT.format(datestr=date_str, wlk=wlk, run=run, bik=bik)
        db[line_inx] = line

    # write to file
    with open(file, 'w') as f:
        f.write("\n".join(db))

    return line


def get_date_counters(date_str):
    # return counters for given date.
    # Example return:
    #   2020-12-01;1;2;3;
    # (1 = COUNT_WALK, 2 = COUNT_RUN, 3 = COUNT_BIKE)
    db = read_file()
    wlk, run, bik = 0, 0, 0
    for line in db:
        if date_str in line:
            line = line.split(";")
            wlk, run, bik = int(line[1]), int(line[2]), int(line[3])

    str_return = WRITE_FMT.format(datestr=date_str, wlk=wlk, run=run, bik=bik)
    return str_return


def on_connect(client, userdata, flags, rc):
    # The callback for when the client connects to the broker
    # Print result of connection attempt
    print("Connected with result code {0}".format(str(rc)))
    # Subscribe to topic & receive any messages published on it
    client.subscribe(topic)


def on_message(client, userdata, msg):
    # The callback for when a publish message is received from the server.
    # Print a received msg
    print(f"Message received [{msg.topic}] : '{msg.payload}'")

    msg = msg.payload.decode("utf-8")
    if "STORE" in msg:
        # store new counters to file.
        # Message format example receive:
        #   STORE;1;2;3
        # return:
        #   STORED;2020-12-01;1;2;3
        # (1 = COUNT_WALK, 2 = COUNT_RUN, 3 = COUNT_BIKE)
        msg = msg.split(";")
        wlk, run, bik = int(msg[1]), int(msg[2]), int(msg[3])
        line_saved = write_file(wlk, run, bik)
        str_return = f"STORED;" + line_saved

    elif "DATE" in msg:
        # search for date in file and return counters. Message format example receive:
        #   DATE:2020-12-01
        # return:
        #   2020-12-01;1;2;3
        # (1 = COUNT_WALK, 2 = COUNT_RUN, 3 = COUNT_BIKE)
        msg = msg.split(":")
        date_str = msg[1]
        str_return = get_date_counters(date_str)

    elif "YESTERDAY" in msg:
        # get yesterday's date and return counters for that date.
        # Message format example receive:
        #   YESTERDAY
        # return:
        #   2020-12-01;1;2;3
        # (1 = COUNT_WALK, 2 = COUNT_RUN, 3 = COUNT_BIKE)
        yesterday = datetime.datetime.now() - datetime.timedelta(days=1)
        date_str = yesterday.strftime("%Y-%m-%d")
        str_return = get_date_counters(date_str)

    else:
        # return error message
        str_return = "ERROR"

    print(f"Sending response msg [{topic}Rec] : '{str_return}'")
    client.publish(topic + "Rec", str_return)


client = mqtt.Client("digi_mqtt_test")  # Create instance of client with client ID “digi_mqtt_test”
client.on_connect = on_connect  # Define callback function for successful connection
client.on_message = on_message  # Define callback function for receipt of a message
client.connect('broker.hivemq.com', 1883, 60)
client.loop_forever()  # Start networking daemon
