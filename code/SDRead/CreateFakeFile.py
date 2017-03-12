import sys, random

if len(sys.argv) != 2:
	print("No file specified.")
	sys.exit(1)

with open(sys.argv[1], "bw") as f:
	for i in range(100):
		data = []
		data.append(random.randint(0, 2**2-1))
		data.append(random.randint(0, 2**8-1))
		data.append(0)
		data = bytes(data)
		f.write(data)
