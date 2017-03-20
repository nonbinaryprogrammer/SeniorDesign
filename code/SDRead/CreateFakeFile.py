import sys, random

if len(sys.argv) != 2:
	print("No file specified.")
	print("USAGE:", sys.argv[0], "<filename>")
	sys.exit(1)

csv = open("output.csv", "w")
csv.write("Sample number, value\n")

with open(sys.argv[1], "bw") as f:
	for i in range(100):
		data = []
		data.append(random.randint(0, 2**2-1))
		data.append(random.randint(0, 2**8-1))
		csv.write(str(i) + ", " + str((data[0] * pow(2, 8)) + (data[1])) + "\n")
		data.append(0)
		data = bytes(data)
		f.write(data)

csv.close()