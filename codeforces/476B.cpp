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

vector <ll> fact(12);

void init()
{
	fact[0] = 1;
	for (int i = 1; i < 12; i++)
		fact[i] = fact[i-1] * i;
}

int nCr(int n, int r)
{
	return (fact[n] / fact[r]) / fact[n-r];
}

int main()
{
	init();

	string s1, s2;
	cin >> s1 >> s2;

	int cnt1 = 0, cnt2 = 0, k = 0;
	for (int i = 0; i < s1.length(); i++)
	{
		(s1[i] == '+') ? cnt1++ : cnt1--;

		if (s2[i] == '+')
			cnt2++;

		else if (s2[i] == '-')
			cnt2--;

		else
			k++;
	}

	int d = abs(cnt1-cnt2);

	if (d-k > 0 || (k-d) % 2)
		cout << setprecision(12) << fixed << (double)0 << "\n";

	else
	{
		cout << setprecision(12) << fixed << ((double)nCr(k, d)) / pow(2, k) << "\n";
	}

	return 0;
}
/*
int main()
{
	string s1, s2;
	cin >> s1 >> s2;

	int c1 = 0, c2 = 0, k = 0;
	for (int i = 0; i < s1.length(); i++)
	{
		(s1[i] == '+') ? c1++ : c1--;

		if (s2[i] == '+')
			c2++;

		else if (s2[i] == '-')
			c2--;

		else
			k++;
	}

	vector < vector <int> > dp(s1.length()+1, vector <int> (21));
	dp[0][10] = 1;
	for (int i = 1; i <= s2.length(); i++)
	{
		for (int j = 0; j < 20; j++)
		{
			if (s2[i-1] == '+' || s2[i-1] == '?')
				dp[i][j+1] += dp[i-1][j];

			if (s2[i-1] == '-' || s2[i-1] == '?')
				dp[i][j-1] += dp[i-1][j];
		}
	}

	cout << setprecision(12) << fixed << dp[s1.length()][c1+10] / pow(2, k) << "\n";

	return 0;
}*/
/*
	0	1	2	3	4	5	6	7	8	9	10	11	12	13	14	15	16	17	18	19
0											1
1												1			
2											1		
3												1
4											1
5												1

*/