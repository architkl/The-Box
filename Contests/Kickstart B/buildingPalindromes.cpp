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
#include <iomanip>
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

	int N, Q, id = 0;
	while (T--)
	{
		id++;

		cin >> N >> Q;

		string S;
		cin >> S;

		vector <vector <int>> pre(N, vector <int> (26));
		pre[0][S[0]-65]++;
		for (int i = 1; i < N; i++)
		{
			for (int j = 0; j < 26; j++)
				pre[i][j] = pre[i-1][j];

			pre[i][S[i]-65]++;
		}

		int l, r, f, ans = 0;
		for (int i = 0; i < Q; i++)
		{
			cin >> l >> r;

			f = 2;

			for (int j = 0; j < 26; j++)
			{
				if (l == 1)
				{
					// cout << "HEHEHEH\n";
					if (pre[r-1][j] % 2)
						f--;
				}

				else if ((pre[r-1][j] - pre[l-2][j]) % 2)
				{
					// cout << "HERE ";
					f--;
				}

				// cout << pre[r-1][j] - pre[l-2][j] << " ";

				if (f == 0)
				{
					// cout << "WRONG ";
					break;
				}
			}

			// cout << "\n";

			if (f)
				ans++;
		}

		cout << "Case #" << id << ": " << ans << "\n";
	}

	return 0;
}