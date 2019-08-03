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
	int T;
	cin >> T;

	string s, c;
	while (T--)
	{
		cin >> s >> c;

		vector < vector <int > > freq_s(s.length()+1, vector <int> (26)), freq_c(c.length()+1, vector <int>(26));
		for (int i = 1; i <= c.length(); i++)
		{
			for (int j = 0; j < 26; j++)
				freq_c[i][j] = freq_c[i-1][j];
			freq_c[i][c[i-1]-97]++;
		}

		for (int i = 1; i <= s.length(); i++)
		{
			for (int j = 0; j < 26; j++)
				freq_s[i][j] = freq_s[i-1][j];
			freq_s[i][s[i-1]-97]++;
		}

		int ans = 0;
		bool f;
		for (int i = c.length(); i <= s.length(); i++)
		{
			f = 1;
			for (int j = 0; j < 26; j++)
			{
				if (freq_s[i][j]-freq_s[i-c.length()][j] != freq_c[c.length()][j] - freq_c[0][j])
				{
					f = 0;
					break;
				}
			}

			ans += f;
		}

		cout << ans << "\n";
	}

	return 0;
}