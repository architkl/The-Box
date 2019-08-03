/*
Author: architkl
Language: C++ 14
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <unordered_map>
#include <stack>
#include <queue>
#include <set>
#include <bitset>
#include <iomanip>
#include <climits>
#include <string>
#include <math.h>

using namespace std;

#define pb push_back
#define mp make_pair

typedef pair <int, int> pii;
typedef unsigned long long ull;
typedef long long ll;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int N;
	cin >> N;

	vector <ll> A(N+1);
	for (int i = 1; i <= N; i++)
		cin >> A[i];

	vector <int> nge_f(N+1, -1);
	int cur = 0;
	stack < pair <ll, int> > S;
	S.push(mp(A[1], 1));
	for (int i = 2; i <= N; i++)
	{
		while (!S.empty() && A[i] > S.top().first)
		{
			nge_f[S.top().second] = i;
			S.pop();
		}

		S.push(mp(A[i], i));
	}

	S.pop();

	vector <int> nge_b(N+1, -1);
	S.push(mp(A[N], N));
	for (int i = N-1; i > 0; i--)
	{
		while (!S.empty() && A[i] > S.top().first)
		{
			nge_b[S.top().second] = i;
			S.pop();
		}

		S.push(mp(A[i], i));
	}

	S.pop();

	for (int i = 1; i <= N; i++)
		cout << nge_f[i] + nge_b[i] << " ";
	
	cout << "\n";

	return 0;
}