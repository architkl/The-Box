#include <iostream>
#include <vector>

using namespace std;

const int N_MAX = 10000;
const int M_MAX = 10000;

int room[N_MAX][M_MAX];

int rec(int n, int m, int t)
{
	int one = 0, f = 0;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			//cout << room[i][j] << "\n";

			if (room[i][j] == 0 || room[i][j] == 3)
				continue;

			if (room[i][j] == 1)
				one = 1;

			if (room[i][j] == 2)
			{
				if (i < n-1 && room[i+1][j] == 1)
				{
					room[i+1][j] = 2;
					f = 1;
				}

				if (i > 0 && room[i-1][j] == 1)
				{
					room[i-1][j] = 2;
					f = 1;
				}

				if (j < n-1 && room[i][j+1] == 1)
				{
					room[i][j+1] = 2;
					f = 1;
				}

				if (j > 0 && room[i][j-1] == 1)
				{
					room[i][j-1] = 2;
					f = 1;
				}

				room[i][j] = 3;
			}
		}
	}

	if (f == 0)
	{
		if (one)
			return -1;

		else
			return t;
	}

	return rec(n, m, t+1);
}

int main()
{
	int n, m;
	cin >> n >> m;

	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> room[i][j];

	int ans = rec(n, m, 0);

	ans == -1 ? cout << "AMIT SURVIVES\n" : cout << ans << "\n";

	return 0;
}