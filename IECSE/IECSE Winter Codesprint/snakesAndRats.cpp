#include <iostream>

using namespace std;

int main()
{
	int N, K;
	cin >> N >> K;

	char grid[N][N];
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			cin >> grid[i][j];

	int rats = 0;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			while (grid[i][j] != 'S' && j < N)
			{
				j++;
			}
			cout << "\n";
			
			if (j >= N)
				break;

			int flag = 0;
			for (int k = K; k >= 1; k--)
			{
				if (j-k < 0)
					continue;

				if (grid[i][j-k] == 'R')
				{
					rats++;
					grid[i][j-k] = 'X';
					flag = 1;
					break;
				}
			}

			if (flag)
				continue;

			for (int k = 1; k <= K; k++)
			{
				if (j+k >= N)
					break;

				if (grid[i][j+k] == 'R')
				{
					rats++;
					grid[i][j+k] = 'X';
					break;
				}	
			}
		}
	}

	cout << rats;

	return 0;
}