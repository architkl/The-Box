#include <bits/stdc++.h>

using namespace std;

int solve(vector<int> &A)
{
	sort(A.begin(), A.end());

	for (int i = 0; i < A.size(); i++)
	{
		while (i+1 < A.size() && A[i] == A[i+1])
			i++;

		if (A[i] == A.size()-i-1)
			return 1;
	}

	return -1;
}

int main()
{
	int n;
	cin >> n;

	vector <int> A(n);
	for (int i = 0; i < n; i++)
		cin >> A[i];

	cout << solve(A) << "\n";

	return 0;
}