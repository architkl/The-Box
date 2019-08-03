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

	int n, m;
	cin >> n >> m;

	int type, k, pos = 0, flip = 1;
	while (m--)
	{
		cin >> type >> k;

		if (type == 1)
		{
			pos += k;
			pos %= n;
		}

		else
		{
			flip *= -1;

			if (k % 2)
			{
				int cw, acw;
				cw = min((k/2-pos+n) % n, (k/2+1-pos+n) % n);
				acw = min((pos-k/2+n) % n, (pos-k/2-1+n) % n);

				if (cw < acw)
					pos = (k/2 + 1 + cw) % n;

				else if (acw < cw)
					pos = (k/2 - acw + n) % n;

				else if (pos == k/2)
					pos = k/2 + 1;

				else if (pos == k/2 + 1)
					pos = k/2;
			}

			else
			{
				int cw = (k/2-pos+n) % n, acw = (pos-k/2+n) % n;

				if (cw < acw)
					pos = (k/2 + cw) % n;

				else if (acw < cw)
					pos = (k/2 - acw + n) % n;
			}
		}
	}

	if (flip == 1)
		cout << 1 << " " << (n-pos) % n << "\n";

	else
		cout << 2 << " " << pos << "\n";

	return 0;
}