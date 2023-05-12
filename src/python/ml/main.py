import numpy as np
import pandas as pd
from glob import glob
from sklearn.model_selection import train_test_split
from sklearn.preprocessing import LabelEncoder
from everywhereml.sklearn.ensemble import RandomForestClassifier

# This params currently achieve 98.38% accuracy on the MotionSense (jogging and walking) test dataset
WINDOW_SIZE = 40   # 0.8 seconds - MotionSense dataset has a sampling rate of 50Hz
N_ESTIMATORS = 20  # number of trees in the forest
NUM_CLASSES = 3    # x, y, z
RANDOM_SEED = 42   # for reproducibility

labels = ["jog", "wlk"]

X, y = np.array([]), []
for label in labels:
    datasets_paths_list = glob(f"data/MotionSense/{label}*/*.csv")

    for datasets_path in datasets_paths_list:
        data = pd.read_csv(datasets_path)
        # add new_X data to X
        new_X = data.iloc[:, -3:].values  # x y z from accelerometer

        # use sliding window to create new_X_50
        new_X = np.array([
            new_X[i:i + WINDOW_SIZE]
            for i
            in range(0, len(new_X) - WINDOW_SIZE, WINDOW_SIZE // 2)])

        # Flatten the windowed data
        new_X = new_X.reshape(new_X.shape[0], -1)

        X = np.vstack((X, new_X)) if X.size else new_X

        # set y to be the same for all rows
        y += [label for _ in range(len(new_X))]

le = LabelEncoder()
y = le.fit_transform(y)

# explore the data
print(X, y)
print(X.shape, y.shape)
print(type(X), type(y))
print(len(X), len(y))

# balance the dataset by taking the minimum number of samples from each label
y_01_len = min([len(y[y == i]) for i in range(len(labels))])
X = np.vstack((X[y == 0][:y_01_len], X[y == 1][:y_01_len]))
y = np.hstack((y[y == 0][:y_01_len], y[y == 1][:y_01_len]))

y_len = len(y)
print(f"Number of samples: {y_len}, per label:")
for i in range(len(labels)):
    print(f"\tLabel {i} ({labels[i]}): {len(y[y == i])} ({len(y[y == i]) / y_len * 100:.2f}%)")

# Split the data into training and test sets
X_train, X_test, y_train, y_test = train_test_split(X, y, test_size=0.2, random_state=RANDOM_SEED)

# Train a RandomForestClassifier model on the preprocessed data
clf = RandomForestClassifier(n_estimators=N_ESTIMATORS, random_state=RANDOM_SEED, verbose=2)
clf.fit(X_train, y_train)

# Evaluate the model on the test set
score = clf.score(X_test, y_test)
print("Accuracy: {:.2f}%".format(score * 100))

print("Exporting to an .h arduino compatible file.")
with open('src/arduino/track/MlClassifier.h', 'w') as f:
    f.write(clf.to_arduino(instance_name='mlClassifier'))

##############################################
# select 20 random samples from the test set #
# and print them in a format that can be     #
# copied to Arduino                          #
##############################################
random_samples = np.random.randint(0, len(X_test), 20)
X_random_samples = X_test[random_samples]
y_random_samples = y_test[random_samples]

for i in range(len(random_samples)):
    print(f"    float input{i}[{WINDOW_SIZE*NUM_CLASSES}] = {{", end="")
    to_print = ""
    for x_elem in X_random_samples[i]:
        to_print += f"{x_elem:.6f}, "
    print(to_print[:-2], "};", sep="")
    print(f"    Serial.println(\"input{i}: \" + String(mlClassifier.predict(input{i})) + \" should be: {y_random_samples[i]}\");")

print("Done.")
