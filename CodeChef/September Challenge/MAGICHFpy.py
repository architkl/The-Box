import sys

def main():
	T = int(input())

	for j in range(T):
		N, X, S = [int(x) for x in input().split()]

		for i in range(S):
			A, B = [int(x) for x in input().split()]

			if (X == A):
				X = B

			elif (X == B):
				X = A

		print(X)

if __name__ == '__main__':
	main()