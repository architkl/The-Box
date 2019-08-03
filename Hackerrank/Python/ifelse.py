import sys

n = int(input())

if (n % 2) or (n > 5 and n < 21):
	print("Weird")

else:
	print("Not Weird")