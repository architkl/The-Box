/*
Author: architkl
Language: C++ 14
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <unordered_map>
#include <queue>
#include <set>
#include <climits>
#include <string>
#include <math.h>

using namespace std;

#define pb push_back
#define mp make_pair

typedef pair <int, int> pii;
typedef unsigned long long ull;

// bool check(vector <int> A, vector <int> B)
// {
// 	for (int i = 0; i < n; i++)
// 		if (A[i] > B[i])
// 			return false;
// }

bool brute(vector <int> A, vector <int> B, int pos)
{
	if (pos == A.size()-2)
	{
		if (A[pos] != B[pos] || A[pos+1] != B[pos+1])
			return false;

		return true;
	}

	if (A[pos] > B[pos])
		return false;

	if (A[pos] < B[pos])
	{
		while (A[pos] < B[pos])
		{
			A[pos] += 1;
			A[pos+1] += 2;
			A[pos+2] += 3;
		}

		return brute(A, B, pos+1);
	}

	return brute(A, B, pos+1);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int T;
	cin >> T;

	int n;
	while (T--)
	{
		cin >> n;

		vector <int> A(n), B(n);
		for (int i = 0; i < n; i++)
			cin >> A[i];

		for (int i = 0; i < n; i++)
			cin >> B[i];

		brute(A, B, 0) ? cout << "YES\n" : cout << "NO\n";
	}

	return 0;
}