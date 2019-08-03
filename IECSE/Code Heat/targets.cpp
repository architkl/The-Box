#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int RANGE = 100005;

bool comp(pair <int, int> a, pair <int, int> b)
{
	return (a.second < b.second);
}

int main()
{
	int T;
	cin >> T;

	int n, c;
	for (int i = 0; i < T; i++)
	{
		cin >> n >> c;

		vector < pair <int, int> > V(n);
		int s, e;
		for (int j = 0; j < n; j++)
		{
			cin >> s >> e;

			V[j] = make_pair(s, e);
		}

		sort(V.begin(), V.end(), comp);
/*
		for (int j = 0; j < n; j++)
			cout << V[j].first << " " << V[j].second << "\n";*/

		int ans = 0;
		for (int j = 0; j < n; j++)
		{
			int k = j+1;
			while (V[k].first <= V[j].second && k < n)
				k++;

			ans++;
			j = k-1;
		}

		cout << ans * c << "\n";
	}

	return 0;
}