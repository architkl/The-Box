#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int ni()
{
	int n;
	cin >> n;

	return n;
}

bool desc(int i, int j)
{
	return (i > j);
}

void print(vector <int> A)
{
	for (int i = 0; i < A.size(); i++)
		cout << A[i] << " ";
	cout << "\n";
}
/*
int k_largest(vector <int> A, int k)
{
	sort(A.begin(), A.end(), desc);

	print(A);

	int sum = 0, n = A.size();
	for (int i = 0; i < k; i++)
		sum += A[i];

	cout << sum << "\n";

	return sum;
}

int k_smallest(vector <int> B, int k)
{
	sort(B.begin(), B.end());

	print(B);

	int sum = 0, n = B.size();
	for (int i = 0; i < k; i++)
		sum += B[i];

	cout << sum << "\n";

	return sum;
}*/

int findsum(vector <int> A)
{
	int n = A.size(), sum = 0;
	for (int i = 0; i < n; i++)
		sum += A[i];

	//cout << sum << "\n";

	return sum;
}

int main()
{
	int T;
	cin >> T;

	int N, K;
	for (int i = 0; i < T; i++)
	{
		cin >> N >> K;

		vector <int> A, B;
		for (int j = 0; j < N; j++)
		{
			if (j % 2 == 0)
				A.push_back(ni());

			else
				B.push_back(ni());
		}

		int sum1 = findsum(A), sum2 = findsum(B);

		sort(A.begin(), A.end(), desc);
		sort(B.begin(), B.end());

		//print(A);
		//print(B);

		int k = 0, x = 0;
		while (A[k] > B[k] && k < K)
		{
			x += 2 * (A[k] - B[k]);
			//cout << "Swapping A[" << k << "] with B[" << k << "]\n";
			k++;
		}

		int diff = sum1 - sum2;

		if (diff < 0)
			cout << "YES\n";

		else
		{
			if (x > diff)
				cout << "YES\n";

			else
				cout << "NO\n";
		}
	}

	return 0;
}