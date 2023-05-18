# a python script to visualize the data from csv

import matplotlib.pyplot as plt
import pandas as pd
import numpy as np

# file_to_read = f"data/bik_0.csv"
file_to_read = f"data/wlk_0.csv"
sensor = "acc"

# read csv
data = pd.read_csv(file_to_read, sep=";")
print(data)

# convert to numpy array
data = data.to_numpy()
print(data)

offset = 0 if sensor == "acc" else 3

# get x, y, z from 1 2 3 columns
x = data[50:150, 1+offset]
y = data[50:150, 2+offset]
z = data[50:150, 3+offset]

# get time
time = np.arange(0, len(x))

# plot
plt.plot(time, x, label="x")
plt.plot(time, y, label="y")
plt.plot(time, z, label="z")
plt.legend()
plt.show()
