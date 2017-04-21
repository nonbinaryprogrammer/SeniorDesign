#import matplotlib lib under namespace plt
import matplotlib.pyplot as plt
from mpl_toolkits.mplot3d import Axes3D #only import Axed3D tool from the mpl_toolkits.mplot3d lib

fig = plt.figure()
ax = fig.add_subplot(111, projection = '3d')

a = 0
b = []
c = []
d = []


#read data from cspacePlotData into lists
f = open("cspacePlotData", "r")

#loop through every line of data and store data string in 'line'
for line in f:
	if  line == '\n':
		ax.scatter(b, c, d)
		plt.savefig(str(a) + 'plot.png')
		#empty contents of lists
		del b[:]
		del c[:]
		del d[:]
		a += 1 #use in output file name
	if len(line) > 1:
		x, y, z = line.split() #split() seperates data by whitespace
		b.append(int(x))
		c.append(int(y))
		d.append(int(z))
