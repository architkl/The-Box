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
#include <bitset>
#include <iomanip>
#include <climits>
#include <string>
#include <math.h>

using namespace std;

#define pb push_back
#define mp make_pair

typedef pair <int, int> pii;
typedef unsigned long long ull;
typedef long long ll;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int h, w;
	cin >> h >> w;

	vector <string> pic(h);
	string s;
	for (int i = 0; i < h; i++)
		cin >> pic[i];

	int num = 0;
	bool f = 0;
	for (int i = 1; i < h-1; i++)
	{
		for (int j = 1; j < w-1; j++)
		{
			if (pic[i][j] == '*' && pic[i-1][j] == '*' && pic[i+1][j] == '*' && pic[i][j-1] == '*' && pic[i][j+1] == '*')
			{
				int k = 0;
				while (j+k < w && pic[i][j+k] == '*')
				{
					pic[i][j+k] = '.';
					k++;
				}

				k = 1;
				while (j-k >= 0 && pic[i][j-k] == '*')
				{
					pic[i][j-k] = '.';
					k++;
				}

				k = 1;
				while (i+k < h && pic[i+k][j] == '*')
				{
					pic[i+k][j] = '.';
					k++;
				}

				k = 1;
				while (i-k >= 0 && pic[i-k][j] == '*')
				{
					pic[i-k][j] = '.';
					k++;
				}

				f = 1;
				break;
			}
		}

		if (f)
			break;
	}

	for (int i = 0; i < h; i++)
	{
		for (int j = 0; j < w; j++)
		{
			if (pic[i][j] == '*')
			{
				f = 0;
				break;
			}
		}
	}

	if (f)
		cout << "YES\n";

	else
		cout << "NO\n";

	return 0;
}