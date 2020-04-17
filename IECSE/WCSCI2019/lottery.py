def count_occ(n, x):
	n = int(n)
	if (n == 0 and x == 0):
		return 1

	occ = 0
	while (n > 0):
		if (n % 10 == x):
			occ = occ + 1

		n = n // 10

	return occ

def main():
	N, Q, X = list(map(int, input().split()))

	lst = list(map(int, input().split()))
	pre = []
	pre.append(0)

	for i in range(1, N+1):
		pre.append(count_occ(lst[i-1], X))

	for i in range(1, N+1):
		pre[i] = pre[i-1] + pre[i]

	for i in range(Q):
		l, r = list(map(int, input().split()))

		print(pre[r] - pre[l-1])

if __name__ == '__main__':
	main()