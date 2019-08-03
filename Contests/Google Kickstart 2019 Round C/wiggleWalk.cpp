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

const int N_MAX = 5e4 + 5;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int T;
	cin >> T;

	int N, R, C, Sr, Sc, case_no = 1;
	string s;
	map <pii, bool> vis;
	pii cur;
	while (T--)
	{
		cin >> N >> R >> C >> Sr >> Sc;

		cin >> s;

		vis.clear();

		cur = mp(Sr, Sc);
		vis[cur] = 1;

		for (int i = 0; i < N; i++)
		{
			// cout << cur.first << " " << cur.second << "\n";
			if (s[i] == 'N')
			{
				int x = 1;
				while (vis[mp(cur.first-x, cur.second)])
					x++;

				cur = mp(cur.first-x, cur.second);
				vis[cur] = 1;
			}

			else if (s[i] == 'S')
			{
				int x = 1;
				while (vis[mp(cur.first+x, cur.second)])
					x++;

				cur = mp(cur.first+x, cur.second);
				vis[cur] = 1;
			}

			else if (s[i] == 'E')
			{
				int x = 1;
				while (vis[mp(cur.first, cur.second+x)])
					x++;

				cur = mp(cur.first, cur.second+x);
				vis[cur] = 1;
			}

			else
			{
				int x = 1;
				while (vis[mp(cur.first, cur.second-x)])
					x++;

				cur = mp(cur.first, cur.second-x);
				vis[cur] = 1;
			}
		}

		cout << "Case #" << case_no << ": " << cur.first << " " << cur.second << "\n";
		case_no++;
	}

	return 0;
}