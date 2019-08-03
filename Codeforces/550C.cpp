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
/*
int main()
{
	string s;
	cin >> s;

	string t = "00" + s;
	vector <int> v(t.length());
	for (int i = 0; i < t.length(); i++)
		v[i] = t[i]-48;

	string ans;
	bool f = 0;
	for (int i = v.size()-3; i >= 0; i--)
	{
		for (int j = v.size()-2; j > i; j--)
		{
			for (int k = v.size()-1; k > j; k--)
			{
				if ((v[i]*100+v[j]*10+v[k]) % 8 == 0)
				{
					ans = t.substr(0, i+1) + t[j] + t[k];
					f = 1;
					break;
				}
			}

			if (f)
				break;
		}

		if (f)
			break;
	}

	ans.erase(0, 2);

	cout << (f ? "YES\n" + ans + "\n" : "NO\n");

	return 0;
}
*/

int main()
{
	string s;
	cin >> s;

	int dp[s.length()+1][8], prev[s.length()+1][8];
	for (int i = 0; i <= s.length(); i++)
	{
		for (int j = 0; j < 8; j++)
		{
			dp[i][j] = 0;
			prev[i][j] = -1;
		}
	}

	for (int i = 1; i <= s.length(); i++)
	{
		dp[i][(s[i-1]-'0') % 8] = 1;

		for (int j = 0; j < 8; j++)
		{
			if (!dp[i-1][j])
				continue;

			dp[i][(j*10 + s[i-1] - '0') % 8] = 1;
			prev[i][(j*10 + s[i-1] - '0') % 8] = j;
			dp[i][j] = 1;
			prev[i][j] = j;
		}
	}

	/*for (int i = 0; i <= s.length(); i++)
	{
		for (int j = 0; j < 8; j++)
			cout << dp[i][j] << " ";
		cout << "\n";
	}

	for (int i = 0; i <= s.length(); i++)
	{
		for (int j = 0; j < 8; j++)
			cout << prev[i][j] << " ";
		cout << "\n";
	}*/

	if (!dp[s.length()][0])
		cout << "NO\n";

	else
	{
		cout << "YES\n";

		string t = "";
		int j = 0;
		for (int i = s.length(); i > 0; i--)
		{
			if (dp[i-1][j])
				continue;

			t += s[i-1];
			j = prev[i][j];

			if (j == -1)
				break;
		}

		reverse(t.begin(), t.end());

		cout << t << "\n";
	}
}