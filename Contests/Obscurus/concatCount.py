import math

m = int(1e9+7)

def main():
	s = input()

	n = int(input())

	c = 0

	for i in range(1, int(len(s) // 2)+1):
		if (len(s) % i == 0):
			# print(s[0:i] + ' ' + str(s.count(s[0:i])))
			if (s.count(s[0:i]) == len(s) // i):
				c = i
				# print(c)
				break

	if (c == 0):
		c = len(s)

	print((n // c) % m)

if __name__ == '__main__':
	main()