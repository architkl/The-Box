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

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int T;
	cin >> T;

	int N, K;
	while (T--)
	{
		cin >> N >> K;

		vector <int> H(N), idx;
		for (int i = 0; i < N; i++)
		{
			cin >> H[i];

			if (H[i] == K)
				idx.pb(i);
		}

		int lb, hb, ans = 0;
		for (int i = 0; i < idx.size(); i++)
		{
			int l = 1, r = 0;
			while (idx[i]-l >= 0 && H[idx[i]-l] > K)
				l++;

			while (idx[i]+r < N && H[idx[i]+r] >= K)
				r++;

			ans += l * r;
		}

		cout << ans << "\n";
	}

	return 0;
}