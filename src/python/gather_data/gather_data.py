# Python script for receiving data over MQTT protocol
# In code for ESP8266, we publish data to the channel, while here, we subscribe to the channel to receive data. 
# Prerequisites: paho.mqtt library

import paho.mqtt.client as mqtt

topic = "AljazACCData"

# 0 = walk
# 1 = run
# 2 = bike
# 9 = no activity
option = 99
file_to_write = f"recording{option}.csv"
clear = False

# clear file
if clear:
    with open(file_to_write, 'w') as f:
        f.write('')
#with open(file_to_write, 'w') as f:
#    f.write('')

def on_connect(client, userdata, flags, rc):  # The callback for when the client connects to the broker
    print("Connected with result code {0}".format(str(rc)))  # Print result of connection attempt
    client.subscribe(topic)  # Subscribe to the topic “digitest/test1”, receive any messages published on it


def on_message(client, userdata, msg):  # The callback for when a PUBLISH message is received from the server.
    print("Message received-> " + msg.topic + " " + str(msg.payload))  # Print a received msg
    with open(file_to_write, 'a') as f:
        f.write(msg.payload.decode("utf-8") + '\n')
        # f.write(str(msg.payload) + '\n')
    #
    # if not "REC" in msg.payload.decode("utf-8"):
    # client.publish(topic+"Rec", "server received-> " + msg.topic + " " + str(msg.payload))


client = mqtt.Client("digi_mqtt_test")  # Create instance of client with client ID “digi_mqtt_test”
client.on_connect = on_connect  # Define callback function for successful connection
client.on_message = on_message  # Define callback function for receipt of a message
client.connect('broker.mqtt-dashboard.com', 1883, 60)
#client.connect('127.0.0.1', 17300)
client.loop_forever()  # Start networking daemon