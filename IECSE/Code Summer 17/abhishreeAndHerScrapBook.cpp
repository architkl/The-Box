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
	int Q;
	cin >> Q;

	char c;
	int x, cnt = 0;
	queue <int> scrap;
	while (Q--)
	{
		cin >> c;

		if (c == 'A')
		{
			if (scrap.empty())
				cout << ++cnt << "\n";

			else
			{
				cout << scrap.front() << "\n";
				cnt++;
				scrap.pop();
			}
		}

		else
		{
			cin >> x;

			cnt--;
			scrap.push(x);
		}
	}

	cout << cnt << "\n";

	return 0;
}