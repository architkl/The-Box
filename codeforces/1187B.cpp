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

void print(vector <int> v)
{
	for (auto i : v)
		cout << i << " ";
	cout << "\n";
}

bool check(vector <int> req, vector <int> ex)
{
	for (int i = 0; i < 26; i++)
		if (ex[i] < req[i])
			return false;

	return true;
}

int main()
{
	int n;
	cin >> n;

	string s;
	cin >> s;
	
	int m;
	cin >> m;

	vector <string> t(m);
	for (int i = 0; i < m; i++)
		cin >> t[i];

	map <char, vector <int> > mymap;
	for (int i = 0; i < s.length(); i++)
		mymap[s[i]].pb(i);

	int ans;
	for (int i = 0; i < m; i++)
	{
		ans = 0;
		vector <int> cnt(26);
		for (int j = 0; j < t[i].length(); j++)
			cnt[t[i][j]-97]++;
		// print(cnt);

		for (int j = 0; j < t[i].length(); j++)
		{
			// cout << t[i][j] << " " << cnt[t[i][j]-97]-1 << " " << mymap[t[i][j]][cnt[t[i][j]-97]-1] << "\n";
			ans = max(ans, mymap[t[i][j]][cnt[t[i][j]-97]-1]);
		}

		cout << ans+1 << "\n";
	}
	
	return 0;
}