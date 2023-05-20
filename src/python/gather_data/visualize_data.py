# a python script to visualize the data from csv

import matplotlib.pyplot as plt
import pandas as pd
import numpy as np


exercise = "bik"
thresh = 1.2
# exercise = "wlk"
# thresh = 1.8
# exercise = "run"
# thresh = 2.0

inx_from = 1000
inx_to = inx_from + 222

sensor = "acc"
file_to_read = f"data/{exercise}_0.csv"


# read csv
data = pd.read_csv(file_to_read, sep=";")
# print(data)

# convert to numpy array
data = data.to_numpy()
# print(data)

offset = 0 if sensor == "acc" else 3

# get x, y, z from 1 2 3 columns
x = data[inx_from:inx_to, 1+offset]
y = data[inx_from:inx_to, 2+offset]
z = data[inx_from:inx_to, 3+offset]

xyz = np.sqrt(x**2 + y**2 + z**2)

# get time
time = np.arange(0, len(xyz))

# number of peaks above threshold for x with a moving window of 10
def find_peaks(x, threshold, window_size=5, away_from_previous_peak=10):
    peak_indeces = []
    for i in range(0, len(x)-window_size, window_size):
        win = x[i:i+window_size]
        peaks = np.where(win > threshold)[0]
        # add peak to peak_indeces if its at least 2 away from the previous peak
        for p in peaks:
            print(f"Peaks: {peaks}")
            if len(peak_indeces) == 0 or i+p - peak_indeces[-1] > away_from_previous_peak:
                peak_indeces.append(i + p)
    print(f"Peak indeces: {peak_indeces}")
    return peak_indeces

peaks_xyz = find_peaks(xyz, thresh)

# add vertical lines where peaks are
plt.vlines(peaks_xyz, 0, 3, color="orange", label="peaks")

# add scatter plot where peaks are
plt.scatter(peaks_xyz, [xyz[i] for i in peaks_xyz], c="red", label="peaks")

# plot
plt.plot(time, xyz, label="xyz")
plt.plot(time, x, label="x")
plt.plot(time, y, label="y")
plt.plot(time, z, label="y")

# plt remove x axis
plt.gca().axes.get_xaxis().set_visible(False)

# add title
plt.title(f"EXERCISE: {exercise}, SENSOR: {sensor}, COUNT: {len(peaks_xyz)}", fontsize=18)

# remove figure padding
plt.tight_layout()

# increase figure font size
plt.rcParams.update({'font.size': 16})

# show legend in left down corner
plt.legend(loc="lower right")

plt.savefig(f"report/figures/peaks_{exercise}_{sensor}_from{inx_from}.png", dpi=300)
plt.show()
