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
	while (t--)
	{
		cin >> n;

		vector <int> d(n);
		for (int i = 0; i < n; i++)
			cin >> d[i];

		int j = n-1;
		while (j > 0 && d[j] <= d[j-1])
		{
			j--;
		}

		if (j == 0)
		{
			cout << -1 << "\n";
			continue;
		}

		multiset <int> s;
		for (int i = j-1; i < n; i++)
			s.insert(d[i]);

		auto it = s.upper_bound(d[j-1]);

		for (int i = 0; i < j-1; i++)
			cout << d[i];

		cout << *it;

		s.erase(it);

		for (auto i : s)
			cout << i;

		cout << "\n";
	}

	return 0;
}

/*
5 6 4 3 2 1

12346
*/