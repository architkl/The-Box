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

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;

	vector <int> tiles(n);
	int cnt_1 = 0, cnt_2 = 0;
	for (int i = 0; i < n; i++)
	{
		cin >> tiles[i];

		tiles[i] == 1 ? cnt_1++ : cnt_2++;
	}

	if (cnt_1 == 0 || cnt_2 == 0)
	{
		for (int i = 0; i < n; i++)
			cout << tiles[i] << " ";
		cout << "\n";
	}

	else
	{
		string ans = "2 1 ";
		cnt_2--;
		cnt_1--;
		
		while (cnt_2)
		{
			ans += "2 ";
			cnt_2--;
		}

		while (cnt_1)
		{
			ans += "1 ";
			cnt_1--;
		}

		cout << ans << "\n";
	}

	return 0;
}