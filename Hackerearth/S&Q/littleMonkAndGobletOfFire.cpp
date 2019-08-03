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
	int s, r;
	queue <int> qs[5], order;
	bool ex[5] = {};
	// vector <int> order;

	while (Q--)
	{
		cin >> c;

		if (c == 'E')
		{
			cin >> s >> r;

			if (!ex[s])
			{
				ex[s] = 1;
				order.push(s);
			}

			qs[s].push(r);
		}

		else
		{
			cout << order.front() << " " << qs[order.front()].front() << "\n";
			qs[order.front()].pop();

			if (qs[order.front()].empty())
			{
				ex[order.front()] = 0;
				// order.erase(order.begin());
				order.pop();
			}
		}
	}

	return 0;
}