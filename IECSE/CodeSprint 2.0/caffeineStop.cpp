#include <iostream>
#include <vector>

using namespace std;

bool vis[10000000];

void init()
{
	for (int i = 0; i < 10000000; i++)
		vis[i] = 0;
}

int main()
{
	int n, start, end;
	cin >> n >> start >> end;

	vector <int> A(n);
	int x, y, z;
	cin >> A[0] >> x >> y >> z;

	for (int i = 1; i < n; i++)
	{
		A[i] = (A[i-1] * x + y) % z;
		//cout << i << " " << A[i] << "\n";
		//cout << A[i] << " ";
	}
	//cout << "\n";
	
	
	vector <int> adj[n];
	for (int i = 0; i < n; i++)
	{
		if (i - A[i] < 0)
		{
			if (i + A[i] >= n-1)
			{
				for (int j = 0; j < n; j++)
				{
					adj[i].push_back(j);
				}
			}

			else
			{
				for (int j = 0; j <= i + A[i]; j++)
				{
					adj[i].push_back(j);
				}

				for (int j = n-1; j >= n + i - A[i]; j--)
				{
					adj[i].push_back(j);
				}
			}
		}

		else
		{
			if (i + A[i] >= n-1)
			{
				for (int j = i-A[i]; j < n; j++)
				{
					adj[i].push_back(j);
				}

				for (int j = 0; j <= (i+A[i]) % n; j++)
				{
					adj[i].push_back(j);
				}
			}

			else
			{
				for (int j = i-A[i]; j <= i+A[i]; j++)
				{
					adj[i].push_back(j);
				}
			}
		}
	}

/*	for (int i = 0; i < n; i++)
	{
		if (adj[i].size() == 0)
			continue;

		cout << i << ", " << A[i] << ":\n";
		for (int j = 0; j < adj[i].size(); j++)
		{
			cout << adj[i][j] << " ";
		}
		cout << "\n";
	}
	cout << "\n";*/

	init();

	vector <int> q[2];
	q[0].push_back(start);
	q[1].push_back(0);
	int f = 0, r = 1, cur, flag = 0;
	for (f; f < r; f++)
	{
		cur = q[0][f];

		if (vis[cur])
			continue;

		vis[cur] = 1;

		cout << cur << "\n";

		if (cur == end)
		{					
			cout << q[1][f];
			flag = 1;
			break;
		}
		
		for (int i = 0; i < adj[cur].size(); i++)
		{
			if (vis[adj[cur][i]])
				continue;

			q[0].push_back(adj[cur][i]);
			q[1].push_back(q[1][f] + 1);
			r++;
		}
		//cout << "r: " << r << "\n";
	}																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																				

	if (!flag)
		cout << "sad";

	return 0;
}