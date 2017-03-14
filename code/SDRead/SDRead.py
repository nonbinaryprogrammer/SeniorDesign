import matplotlib.pyplot as plt
import sys

if len(sys.argv) != 2:			# Make sure filename is specified on command line
	print("No file specified.")	
	sys.exit(1)

temps = []							# Create an empty list of temperatures

with open(sys.argv[1], "br") as f:	# Open output file for binary reading
	data = bytes(f.read(3))			# Read three bytes
	while data != bytes(b""):		# Make sure we have input (i.e. not EOF)
		num = (data[0] * pow(2, 8))	# Load the most significant byte
		num += (data[1])			# Load the least significant byte
		temps.append(num)			# Store the number in the array
		data = bytes(f.read(3))		# Get thee next three bytes
	
scaled = [(i/(2**10)) for i in temps] # Scale the temperature values to between 0-1
plt.plot(scaled)					# Create the plot
plt.ylabel("Relative temperature")	# Always label your axises
plt.xlabel("Sample number")			
plt.show()							# Display the plot