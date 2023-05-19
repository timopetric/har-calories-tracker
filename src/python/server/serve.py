# Python script for receiving data over MQTT protocol
# In code for ESP8266, we publish data to the channel, while here, we subscribe to the channel to receive data.
# Prerequisites: paho.mqtt library

import paho.mqtt.client as mqtt
import datetime

topic = "AljazACCData"

WRITE_FMT = "{datestr};{wlk};{run};{bik}"
ESP_SEND_FMT = "{wlk};{run};{bik}"

# 0 = walk
# 1 = run
# 2 = bike

FILE_TO_WRITE = f"store.csv"
def read_file(file=FILE_TO_WRITE):
    with open(file, 'r') as f:
        return [x.strip() for x in f.readlines()]

def write_file(wlk, run, bik, file=FILE_TO_WRITE):
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

def get_date_counters(date_str):
    # return counters for given date.
    # Example return:
    #   2020-12-01;0;0;0;
    db = read_file()
    wlk, run, bik = 0, 0, 0
    for line in db:
        if date_str in line:
            line = line.split(";")
            wlk, run, bik = int(line[1]), int(line[2]), int(line[3])

    str_return = WRITE_FMT.format(datestr=date_str, wlk=wlk, run=run, bik=bik)
    return str_return


def on_connect(client, userdata, flags, rc):  # The callback for when the client connects to the broker
    print("Connected with result code {0}".format(str(rc)))  # Print result of connection attempt
    client.subscribe(topic)  # Subscribe to the topic “digitest/test1”, receive any messages published on it


def on_message(client, userdata, msg):  # The callback for when a PUBLISH message is received from the server.
    print("Message received-> " + msg.topic + " " + str(msg.payload))  # Print a received msg

    if "STORE" in msg.payload.decode("utf-8"):
        # store new counters to file
        msg = msg.payload.decode("utf-8").split(";")
        wlk, run, bik = int(msg[0]), int(msg[1]), int(msg[2])
        write_file(wlk, run, bik)
        str_return = f"STORED"

    elif "DATE" in msg.payload.decode("utf-8"):
        # search for date in file and return counters
        # DATE:2020-12-01
        msg = msg.payload.decode("utf-8").split(":")
        date_str = msg[1]
        str_return = get_date_counters(date_str)

    elif "YESTERDAY" in msg.payload.decode("utf-8"):
        # get yesterday's date and return counters for that date
        yesterday = datetime.datetime.now() - datetime.timedelta(days=1)
        date_str = yesterday.strftime("%Y-%m-%d")
        str_return = get_date_counters(date_str)

    client.publish(topic+"Rec", str_return)


client = mqtt.Client("digi_mqtt_test")  # Create instance of client with client ID “digi_mqtt_test”
client.on_connect = on_connect  # Define callback function for successful connection
client.on_message = on_message  # Define callback function for receipt of a message
client.connect('broker.hivemq.com', 1883, 60)
#client.connect('127.0.0.1', 17300)
client.loop_forever()  # Start networking daemon