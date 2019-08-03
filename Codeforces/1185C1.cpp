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
	// ios_base::sync_with_stdio(false);
	// cin.tie(NULL);

	int n, M;
	cin >> n >> M;

	vector <int> t(n), h1, h2;
	int sum = 0, cpy, ans = 0;
	for (int i = 0; i < n; i++)
	{
		cin >> t[i];
		
		ans = 0;
		cpy = sum;

		while (cpy + t[i] > M)
		{
			cpy -= h2.front();
			ans++;

			pop_heap(h2.begin(), h2.end());
			h2.pop_back();
		}

		sum += t[i];
		h1.pb(t[i]);
		push_heap(h1.begin(), h1.end());
		
		h2 = h1;

		cout << ans << " ";
	}

	cout << "\n";

	return 0;
}