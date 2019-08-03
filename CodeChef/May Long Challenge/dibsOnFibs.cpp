#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

const double Phi = (sqrt(5) + 1) / 2;
const double phi = (sqrt(5) - 1) / 2;
const int K = pow(10, 9) + 7;

long long int coeff(int n)
{
	double P = 1, p = 1;
	for (int i = 0; i < n; i++)
	{
		P *= Phi;
		p *= -phi;

		if (P > K)
			P -= K;

		if (p > K)
			p -= K;
	}

	if (P < p)
		P += K;

	//cout << (P - p) / sqrt(5);
	return ((P - p) / sqrt(5));
}

int main()
{
	int T;
	cin >> T;

	int M, N;
	for (int i = 0; i < T; i++)
	{
		cin >> M >> N;

		vector <int> A(M), B(M);
		long long int result = 0;

		for (int j = 0; j < M; j++)
			cin >> A[j];

		for (int j = 0; j < M; j++)
			cin >> B[j];

		for (int j = 0; j < M; j++)
		{
			for (int k = 0; k < M; k++)
			{
				int f1 = A[j], f2 = B[k];
				long long int fn = coeff(N-2) * f2 + coeff(N-1) * f1;
				result += fn;
				result %= K;
			}
		}

		cout << result << "\n";
	}

	return 0;
}