import sys

n = int(raw_input())
a = map(int, raw_input().split())

a.sort()

f = 0
for x in xrange(0, n-1, 2):
	if (a[x] != a[x+1]):
		f = 1
		print(a[x])
		break

if (f == 0):
	print(a[n-1])