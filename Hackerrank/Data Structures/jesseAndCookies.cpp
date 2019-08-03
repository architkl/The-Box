/*
Author: architkl
Language: C++ 11
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

bool comp(int a, int b)
{
	return (a > b);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int N, K;
	cin >> N >> K;

	vector <ull> A(N);
	for (int i = 0; i < N; i++)
		cin >> A[i];

	make_heap(A.begin(), A.end(), comp);

	ull cookie1, cookie2, op = 0;
	while (A.size() != 1 && A[0] < K)
	{
		cookie1 = A[0];
		pop_heap(A.begin(), A.end(), comp);
		A.pop_back();
		
		cookie2 = A[0];
		pop_heap(A.begin(), A.end(), comp);
		A.pop_back();

		A.pb(cookie1 + 2 * cookie2);
		push_heap(A.begin(), A.end(), comp);

		op++;
	}

	A[0] >= K ? cout << op : cout << -1;

	cout << "\n";

	return 0;
}