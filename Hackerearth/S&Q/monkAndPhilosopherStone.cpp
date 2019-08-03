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

	vector <int> A(N);
	for (int i = 0; i < N; i++)
		cin >> A[i];

	int Q, X;
	cin >> Q >> X;

	string s;
	stack <int> S;
	int val = 0, i = 0;
	bool f = 0;
	while (Q--)
	{
		cin >> s;

		if (f)
			continue;

		if (s == "Harry")
		{
			val += A[i];
			S.push(A[i]);
			i++;

			if (val == X)
				f = 1;
		}

		else
		{
			val -= S.top();
			S.pop();
		}
	}

	f ? cout << S.size() : cout << -1;

	cout << "\n";

	return 0;
}