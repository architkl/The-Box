#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int n;
	cin >> n;

	vector < pair <int, int> > road[n+1];
	pair <int, int> p;
	int u, v;
	for (int i = 0; i < n-1; i++)
	{
		cin >> u >> v;

		p = make_pair(u, v);
		road[u].push_back(p);

		p = make_pair(v, u);
		road[v].push_back(p);
	}

	for (int i = 1; i <= n; i++)
	{
		vector < pair <int, int> > temp[n+1];
		for (int j = 1; j <= n; j++)
		{
			if (j == i)
				continue;

			for (int k = 0; k < road[j].size(); k++)
			{
				if (road[j][k].second == i)
					continue;

				temp[j].push_back(road[j][k]);
			}
		}

		int index = 1;
		for (int i = 2; i <= n; i++)
			if (temp[i].size() > temp[index].size())
				index = i;

		if (temp[index].size()-1 > n/2)
		{
			cout << "NO ";
			continue;
		}

		else
		{
			
		}
	}

	return 0;
}