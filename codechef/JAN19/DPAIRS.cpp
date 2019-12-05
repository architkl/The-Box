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

bool comp(pii a, pii b)
{
	return (a.first < b.first);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int N, M;
	cin >> N >> M;

	vector <pii> A, B;
	int t;
	for (int i = 0; i < N; i++)
	{
		cin >> t;

		A.pb(mp(t, i));
	}

	for (int i = 0; i < M; i++)
	{
		cin >> t;

		B.pb(mp(t, i));
	}

	sort(A.begin(), A.end(), comp);
	sort(B.begin(), B.end(), comp);

	for (int i = 0; i < M; i++)
		cout << A[0].second << " " << B[i].second << "\n";

	for (int i = 1; i < N; i++)
		cout << A[i].second << " " << B[M-1].second << "\n";

	return 0;
}