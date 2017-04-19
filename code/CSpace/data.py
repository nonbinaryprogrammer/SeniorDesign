#import matplotlib lib under namespace plt
import matplotlib.pyplot as plt
from mpl_toolkits.mplot3d import Axes3D #only import Axed3D tool from the mpl_toolkits.mplot3d lib

fig = plt.figure()
ax = fig.add_subplot(111, projection = '3d')

b = []
c = []
d = []

#read data from cspacePlotData into lists
f = open("cspacePlotData", "r")

#loop through every line of data and store data string in 'line'
for line in f:
	x, y, z = line.split() #split() seperates data by whitespace
	b.append(int(x))
	c.append(int(y))
	d.append(int(z))

ax.scatter(b, c, d)
plt.show()