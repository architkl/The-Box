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

const int N_MAX = 21;

int main()
{
	vector < vector <int> > ans(N_MAX);
	int cnt, temp;
	ans[0].pb(1);
	for (int i = 0; i < N_MAX-1; i++)
	{
		for (int j = 0; j < ans[i].size();)
		{
			temp = ans[i][j];
			cnt = 0;

			while (j < ans[i].size() && ans[i][j] == temp)
			{
				cnt++;
				j++;
			}

			ans[i+1].pb(cnt);
			ans[i+1].pb(temp);
		}
	}
	
	int t;
	cin >> t;

	int n;
	while (t--)
	{
		cin >> n;

		for (auto i : ans[n-1])
			cout << i;
		cout << "\n";
	}

	return 0;
}