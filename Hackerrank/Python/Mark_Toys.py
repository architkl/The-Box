import sys

def max_toys(n, k):
	toys.sort()
	count = 0
	for x in xrange(n):
		if (k - toys[x] < 0):
			break
		k -= toys[x]
		count += 1
	return count

n, k = map(int, raw_input().split())
toys = map(int, raw_input().split())

print(max_toys(n, k))