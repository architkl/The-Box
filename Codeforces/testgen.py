import random
import numpy

def gen(size, t):
	out = str(size) + "\n"
	for i in range(t):
		nums = numpy.random.randint(1, 1000000, size)

		# out += str(size) + "\n"
		out += " ".join(map(str, nums))
		out += "\n"
	return out

def main():
	size = [200000]

	for i in range(1):
		filename = "input.txt"
		file = open(filename, "w+")
		file.writelines(gen(size[i], 1))

if __name__ == '__main__':
	main()