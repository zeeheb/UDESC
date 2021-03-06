# -*- coding: utf-8 -*-
"""mnist.ipynb

Automatically generated by Colaboratory.

Original file is located at
    https://colab.research.google.com/drive/13isI8yMQoSy2ztbfAyd2bltVrNUcHJuX
"""

import numpy as np
import matplotlib.pyplot as plt
# %matplotlib inline
plt.rcParams['figure.figsize'] = (7,7)

from keras.datasets import mnist
from keras.models import Sequential
from keras.layers.core import Dense, Dropout, Activation
from keras.utils import np_utils

nb_classes = 10
(x_train, y_train), (x_test, y_test) = mnist.load_data()
print("x train original shape", x_train.shape)
print("y_train original shape", y_train.shape)

for i in range(9):
  plt.subplot(3,3,i+1)
  plt.imshow(x_train[i], cmap='gray', interpolation='none')
  plt.title("Class {}", format(y_train.))

x_train = x_train.reshape(60000, 784)
x_test = x_test.reshape(10000, 784)
x_train = x_train.astype('float32')
x_test = x_test.astype('float32')
x_train /= 255
x_test /= 255
print ("training matrix shape", x_train.shape)
print ("testing matrix shape", x_test.shape)

model = Sequential()
model.add(Dense(512, input_shape=(784,)))
model.add(Activation('relu'))
model.add(Dropout(0,2))
model.add(Dense(512))
model.add(Activation('relu'))
model.add(Dropout(0,2))
model.add(Dense(10))
model.add(Activation('softmax'))

model.compile(loss='categorical_crossentropy', optimizer='adam', metrics=['accuracy'])

model.fit(x_train, batch_size=128, nb_epoch=7,
          verbose=1,
          validation_data=(x_test, y_test))