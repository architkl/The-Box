#include <bits/stdc++.h>

using namespace std;

int maxSubArray(const vector<int> &A)
{
	int g_max = INT_MIN, temp_max = 0;
	for (int i = 0; i < A.size(); i++)
	{
		temp_max += A[i];
		
		g_max = max(g_max, temp_max);

		if (temp_max + A[i] < 0)
			temp_max = 0;
	}

	return g_max;
}

int main()
{
	int n;
	cin >> n;

	vector <int> A(n);
	for (int i = 0; i < n; i++)
		cin >> A[i];

	cout << maxSubArray(A) << "\n";

	return 0;
}