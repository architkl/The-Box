import sys

def main():
	t = int(input())

	for i in range(t):
		T, N, X, F = input().split();

		T = int(T)
		N = int(N)
		X = int(X)
		F = float(F)

		users = N

		for j in range(T):
			N = N * 3 * X / 2
			users += N
			X *= F

		print(int(users))

if __name__ == '__main__':
	main()