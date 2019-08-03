#include <iostream>
#include <vector>
#include <utility>
#include <fstream>

using namespace std;

const int N_MAX = 105;

bool vis[N_MAX][N_MAX];

char arr[N_MAX][N_MAX];

void ini()
{
	for (int i = 0; i < N_MAX; i++)
		for (int j = 0; j < N_MAX; j++)
			vis[i][j] = 0;
}
//int dest_x, dest_y;
//int N;
/*
int min_steps(int cur_x, int cur_y, int steps, int turn)
{
	if ( (arr[cur_x][cur_y] == 'X') || (cur_x < 0 || cur_x == N) || (cur_y < 0 || cur_y == N) )
		return N_MAX;

	if (cur_x == dest_x && cur_y == dest_y)
		return steps;

	int mn = N_MAX;
	steps++;
	
	if (turn)
	{
		for (int i = 1; cur_x + i < N; i++)
			mn = min(mn, min_steps(cur_x + i, cur_y, steps, 0));

		for (int i = 1; cur_x - i >= 0; i++)
			mn = min(mn, min_steps(cur_x - i, cur_y, steps, 0));
	}
	
	else
	{
		for (int i = 1; cur_y + i < N; i++)
			mn = min(mn, min_steps(cur_x, cur_y + i, steps, 1));

		for (int i = 1; cur_y - i >= 0; i++)
			mn = min(mn, min_steps(cur_x, cur_y - i, steps, 1));
	}

	return mn;
}
*/

int main()
{
	ifstream fi("test.txt");

	int n;
	//cin >> n;
	fi >> n;

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			//cin >> arr[i][j];
			fi >> arr[i][j];

	int initX, initY, wantX, wantY;
	//cin >> initX >> initY >> wantX >> wantY;
	fi >> initX >> initY >> wantX >> wantY;

	fi.close();
/*
	dest_x = wantX;
	dest_y = wantY;
	N = n;

	cout << min(min_steps(initX, initY, 0, 0), min_steps(initX, initY, 0, 1));
*/

	ini();

	vector < pair <int, int> > q;
	vector <int> dist;	
	vector < pair <int, int> >::iterator q_it;
	vector <int>::iterator dist_it;

	q.push_back(make_pair(initX, initY));
	dist.push_back(0);
	q_it = q.begin();
	dist_it = dist.begin();

	for (; q_it != q.end(); q_it++, dist_it++)
	{
		cout << q_it->first << " " << q_it->second << "\n";

		if (q_it->first == wantX && q_it->second == wantY)
			break;

		int temp_x = q_it->first, temp_y = q_it->second;
		//cout << temp_x + 1 << temp_y << "\n";
		//cout << vis[temp_x + 1][temp_y] << "\n";
		//cout << q_it->second << "\n";
		while (temp_x + 1 != n)
		{
			cout << q_it->first << " " << q_it->second << "\t";
			//cout << temp_x + 1 << " " << temp_y << "\t";
			if (vis[temp_x + 1][temp_y] == 1)
			{
				temp_x++;
				continue;
			}

			if (arr[temp_x + 1][temp_y] == 'X')
				break;
			
			q.push_back(make_pair(temp_x + 1, temp_y));
			dist.push_back(*dist_it + 1);
			vis[temp_x + 1][temp_y] = 1;
			temp_x++;
		}
		cout << "\n";

		//cout << q_it->second << " " << temp_y << "\n";
		temp_x = q_it->first;
		//cout << temp_x - 1 << " " << temp_y << "\n";
		//cout << vis[temp_x - 1][temp_y] << "\n";
		//cout << arr[temp_x - 1][temp_y] << "\n";
		//cout <<"G";
		while (temp_x - 1 >= 0)
		{
			cout << q_it->first << " " << q_it->second << "\t";
			//cout << temp_x - 1 << " " << temp_y << "\t";
			if (vis[temp_x - 1][temp_y] == 1)
			{
				temp_x--;
				continue;
			}

			if (arr[temp_x - 1][temp_y] == 'X')
				break;
			
			q.push_back(make_pair(temp_x - 1, temp_y));
			dist.push_back(*dist_it + 1);
			vis[temp_x - 1][temp_y] = 1;
			temp_x--;
		}
		cout << "\n";
		//cout << q_it->first << " " << q_it->second << "\n";
		temp_x = q_it->first;
		temp_y = q_it->second;
		//cout << temp_x << " " << temp_y << "\n";
		while (temp_y + 1 != n)
		{
			cout << q_it->first << " " << q_it->second << "\t";
			//cout << temp_x << " " << temp_y + 1 << "\t";
			if (vis[temp_x][temp_y + 1] == 1)
			{
				temp_y++;
				continue;
			}

			if (arr[temp_x][temp_y + 1] == 'X')
				break;
			
			q.push_back(make_pair(temp_x, temp_y + 1));
			dist.push_back(*dist_it + 1);
			vis[temp_x][temp_y + 1] = 1;
			temp_y++;
		}
		cout << "\n";

		temp_y = q_it->second;
		while (temp_y - 1 >= 0)
		{
			cout << q_it->first << " " << q_it->second << "\t";
			//cout << temp_x << " " << temp_y - 1 << "\t";
			if (vis[temp_x][temp_y - 1] == 1)
			{
				temp_y--;
				continue;
			}

			if (arr[temp_x][temp_y - 1] == 'X')
				break;
			
			q.push_back(make_pair(temp_x, temp_y - 1));
			dist.push_back(*dist_it + 1);
			vis[temp_x][temp_y - 1] = 1;
			temp_y--;
		}
		cout << "\n";
	}

	cout << *dist_it << "\n";

	return 0;
}