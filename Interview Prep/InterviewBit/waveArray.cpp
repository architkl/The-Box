#include <bits/stdc++.h>

using namespace std;

vector<int> wave(vector<int> &A)
{
	sort(A.begin(), A.end());

	for (int i = 0; i+1 < A.size(); i+=2)
	{
		A[i] ^= A[i+1];
		A[i+1] ^= A[i];
		A[i] ^= A[i+1];
	}

	return A;
}

int main()
{
	int n;
	cin >> n;

	vector <int> A(n);
	for (int i = 0; i < n; i++)
		cin >> A[i];

	A = wave(A);
	for (auto i : A)
		cout << i << " ";
	cout << "\n";

	return 0;
}