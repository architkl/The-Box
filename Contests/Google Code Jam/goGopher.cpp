#include <iostream>

using namespace std;

int G[1000][1000];

void ini()
{
	for (int i = 0; i < 1000; i++)
		for (int j = 0; j < 1000; j++)
			G[i][j] = 0;
}

int main()
{
	int T;
	cin >> T;

	int A, out_x = 100, out_y = 100, in_x = -2, in_y = -2;
	for (int i = 0; i < T; i++)
		cin >> A;
	
	ini();

	cout << out_x << " " << out_y << "\n";
	cin >> in_x >> in_y;
	G[in_x][in_y] = 1;

	while ( !(in_x == 0 && in_y == 0) && !(in_x == -1 && in_y == -1) )
	{
		if (in_x == out_x && in_y == out_y)
		{
			if (G[out_x][out_y + 1] == 0)
				out_y++;

			else if (G[out_x][out_y - 1] == 0)
				out_y--;

			else if (G[out_x + 1][out_y] == 0)
				out_x++;

			else if (G[out_x - 1][out_y] == 0)
				out_x--;

			else if (G[out_x + 1][out_y + 1] == 0)
			{
				out_x++;
				out_y++;
			}

			else if (G[out_x + 1][out_y - 1] == 0)
			{
				out_x++;
				out_y--;
			}

			else if (G[out_x - 1][out_y + 1] == 0)
			{
				out_x--;
				out_y++;
			}

			else if (G[out_x - 1][out_y - 1] == 0)
			{
				out_x--;
				out_y--;
			}

			else
				out_y++;
		}

		cout << out_x << " " << out_y << "\n";
		cin >> in_x >> in_y;
		G[in_x][in_y] = 1;
	}
}