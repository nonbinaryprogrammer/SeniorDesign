import matplotlib.pyplot as plt
import sys

if len(sys.argv) != 2:
	print("No file specified.")
	sys.exit(1)

temps = []

with open(sys.argv[1], "br") as f:
	data = bytes(f.read(3))
	while data != bytes(b""):
		#print(repr(data[0]), repr(data[1]))
		temps.append((data[0] * pow(2, 8)) + (data[1]))
		data = bytes(f.read(3))
	
plt.plot([(i/(2**10)) for i in temps])
plt.ylabel("Relative temperature")
plt.xlabel("Sample number")
plt.show()