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

	int t;
	cin >> t;

	int n;
	string s;
	while (t--)
	{
		cin >> n;

		vector <int> team(n);

		for (int i = 0; i < n; i++)
			cin >> s >> team[i];

		sort(team.begin(), team.end());

		long long int bad = 0;
		int rank = 1;
		for (int i = 0; i < n; i++)
		{
			bad += abs(team[i] - rank);
			rank++;
		}
		
		cout << bad << "\n";
	}

	return 0;
}