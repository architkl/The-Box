#include <iostream>
#include <vector>

using namespace std;

const int N_MAX = 1005;

bool vis[N_MAX][N_MAX];

void init()
{
	for (int i = 0; i < N_MAX; i++)
		for (int j = 0; j < N_MAX; j++)
			vis[i][j] = 0;
}

int bfs(int N, int x, int y)
{
	vector < pair <int, pair <int, int> > > q;
	vector < pair <int, pair <int, int> > >::iterator it;

	q.push_back(make_pair(0, make_pair(x, y)));
	it = q.begin();
	vis[x][y] = 1;

	for (int i = 0; i < q.size(); i++)
	{
		//cout << q[i].first << "\n";

		if (q[i].second.first == N && q[i].second.second == N)
			return q[i].first;

		if ( (q[i].second.first + 2 <= N && q[i].second.second + 1 <= N) && !vis[q[i].second.first + 2][q[i].second.second + 1] )
		{
			//cout << "PUSH\n";
			q.push_back(make_pair(q[i].first + 1, make_pair(q[i].second.first + 2, q[i].second.second + 1)));
			vis[q[i].second.first + 2][q[i].second.second + 1] = 1;
		}

		if ( (q[i].second.first + 2 <= N && q[i].second.second - 1 > 0) && !vis[q[i].second.first + 2][q[i].second.second - 1] )
		{
			//cout << "PUSH\n";
			q.push_back(make_pair(q[i].first + 1, make_pair(q[i].second.first + 2, q[i].second.second - 1)));
			vis[q[i].second.first + 2][q[i].second.second - 1]  = 1;
		}

		if ( (q[i].second.first + 1 <= N && q[i].second.second + 2 <= N) && !vis[q[i].second.first + 1][q[i].second.second + 2] )
		{
			//cout << "PUSH\n";
			q.push_back(make_pair(q[i].first + 1, make_pair(q[i].second.first + 1, q[i].second.second + 2)));
			vis[q[i].second.first + 1][q[i].second.second + 2] = 1;
		}

		if ( (q[i].second.first + 1 <= N && q[i].second.second - 2 > 0) && !vis[q[i].second.first + 1][q[i].second.second - 2] )
		{
			//cout << "PUSH\n";
			q.push_back(make_pair(q[i].first + 1, make_pair(q[i].second.first + 1, q[i].second.second - 2)));
			vis[q[i].second.first + 1][q[i].second.second - 2]  = 1;
		}

		if ( (q[i].second.first - 1 > 0 && q[i].second.second + 2 <= N) && !vis[q[i].second.first - 1][q[i].second.second + 2] )
		{
			//cout << "PUSH\n";
			q.push_back(make_pair(q[i].first + 1, make_pair(q[i].second.first - 1, q[i].second.second + 2)));
			vis[q[i].second.first - 1][q[i].second.second + 2]  = 1;
		}

		if ( (q[i].second.first - 1 > 0 && q[i].second.second - 2 > 0) && !vis[q[i].second.first - 1][q[i].second.second - 2] )
		{
			//cout << "PUSH\n";
			q.push_back(make_pair(q[i].first + 1, make_pair(q[i].second.first - 1, q[i].second.second - 2)));
			vis[q[i].second.first - 1][q[i].second.second - 2]  = 1;
		}

		if ( (q[i].second.first - 2 > 0 && q[i].second.second + 1 <= N) && !vis[q[i].second.first - 2][q[i].second.second + 1] )
		{
			//cout << "PUSH\n";
			q.push_back(make_pair(q[i].first + 1, make_pair(q[i].second.first - 2, q[i].second.second + 1)));
			vis[q[i].second.first - 2][q[i].second.second + 1]  = 1;
		}

		if ( (q[i].second.first - 2 > 0 && q[i].second.second - 1 > 0) && !vis[q[i].second.first - 2][q[i].second.second - 1] )
		{
			//cout << "PUSH\n";
			q.push_back(make_pair(q[i].first + 1, make_pair(q[i].second.first - 2, q[i].second.second - 1)));
			vis[q[i].second.first - 2][q[i].second.second - 1]  = 1;
		}
	}

	return -1;
}

int main()
{
	// vector < pair <int, pair <int, int> > > q;
	// vector < pair <int, pair <int, int> > >::iterator it;

	// q.push_back(make_pair(0, make_pair(0, 0)));
	// it = q.begin();

	// cout << it->second.first;
	int T;
	cin >> T;

	int N, x, y;
	for (int i = 0; i < T; i++)
	{
		cin >> N >> x >> y;

		init();

		cout << bfs(N, x, y) << "\n";
	}

	return 0;
}