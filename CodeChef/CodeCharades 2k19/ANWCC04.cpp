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

	int ans, x, f;
	string str;
	while (T--)
	{
		cin >> str;

		x = 0;
		ans = 0;
		f = -1;

		for (int i = 0; i < str.length(); i++)
		{
			if (str[i] == '+')
			{
				x /= 10;
				// cout << x << " " << ans << "\n";

				f ? ans += x : ans -= x;
				
				f = 1;
				x = 0;
			}

			else if (str[i] == '-')
			{
				x /= 10;
				// cout << x << " " << ans << "\n";
				
				f ? ans += x : ans -= x;
				f = 0;
				x = 0;
			}

			else if (str[i] == '=')
			{
				x /= 10;
				f ? ans += x : ans -= x;
				// cout << x << " " << ans << "\n";
				x = 0;

				for (int j = i+1; j < str.length(); j++)
				{
					x += str[j] - 48;
					x *= 10;
				}

				x /= 10;

				break;
			}

			else
			{
				x += str[i] - 48;
				x *= 10;
			}
		}

		if (ans == x)
			cout << "Valid Equation\n";

		else
			cout << "Invalid Equation\n";
	}

	return 0;
}