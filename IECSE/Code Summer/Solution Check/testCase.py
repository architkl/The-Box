import sys
import random

file_object = open("Input", "w")

low, high = 0, 1000000000000000000
size = 10000

file_object.write('{}\n'.format(size))

for i in range(size):
	n = random.randint(low, high)
	m = random.randint(low, 1000)

	file_object.write('{} {}\n'.format(n, m))

file_object.close()