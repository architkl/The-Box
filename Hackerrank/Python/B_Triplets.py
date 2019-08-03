import sys

n, d = map(int, raw_input().split())
arr = map(int, raw_input().split())

count = 0

for i in xrange(len(arr)-2):
	if arr[i]+d in arr and arr[i] + 2*d in arr:
		count += 1

print(count)