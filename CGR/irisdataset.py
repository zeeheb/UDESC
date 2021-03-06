# -*- coding: utf-8 -*-
"""irisdataset.ipynb

Automatically generated by Colaboratory.

Original file is located at
    https://colab.research.google.com/drive/1zRLZ-On9gK7xPIRTRc6stzG7as125G8B
"""

from sklearn.datasets import load_iris
from sklearn.model_selection import train_test_split
from sklearn.neighbors import KNeighborsClassifier
from sklearn import metrics
import numpy as np
import matplotlib.pyplot as plt
# %matplotlib inline
print ("libs importadas")

iris = load_iris()
type(iris)
iris.data[0]

iris.feature_names

iris.target

iris.target_names

iris.data.shape

x = iris.data
y = iris.target
x_train, x_test, y_train, y_test = train_test_split(x,y,test_size=0.50,random_state=4)

print (x_train.shape)
print (x_test.shape)
print (y_train.shape)
print (y_test.shape)

k_range = range (1,26)
scores = {}
scores_list = []
for k in k_range:
    knn = KNeighborsClassifier(n_neighbors=k)
    knn.fit(x_train, y_train)
    y_pred = knn.predict(x_test)
    scores[k] = metrics.accuracy_score(y_test, y_pred)
    scores_list.append(metrics.accuracy_score(y_test, y_pred))
    

scores

plt.plot(k_range, scores_list)
plt.xlabel('value of K for KNN')
plt.ylabel('testing accuracy')

