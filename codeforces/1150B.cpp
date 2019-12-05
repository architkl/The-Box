/*
Author: architkl
Language: C++ 14
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <unordered_map>
#include <stack>
#include <queue>
#include <set>
#include <iomanip>
#include <climits>
#include <string>
#include <math.h>

using namespace std;

#define pb push_back
#define mp make_pair

typedef pair <int, int> pii;
typedef unsigned long long ull;

bool check(char a, char b, char c, char d, char e)
{
	if (a == '.' && b == '.' && c == '.' && d == '.' && e == '.')
		return true;

	return false;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;

	char board[n][n];
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> board[i][j];
	
	for (int i = 1; i < n-1; i++)
	{
		for (int j = 1; j < n-1; j++)
		{
			if (check(board[i][j-1], board[i][j], board[i-1][j], board[i+1][j], board[i][j+1]))
				board[i][j-1] = board[i][j] = board[i-1][j] = board[i+1][j] = board[i][j+1] = '#';
		}
	}

	bool f = true;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (board[i][j] == '.')
			{
				f = 0;
				break;
			}
		}

		if (!f)
			break;
	}

	f ? cout << "YES\n" : cout << "NO\n";

	return 0;
}