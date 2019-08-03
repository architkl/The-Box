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

stack <int> S;
string weight;
int m;

bool dfs(int x, int cnt, int sum1, int sum2)
{
	// cout << "";
	if (cnt == m+1)
		return 1;

	bool temp;
	for (int i = 0; i < 10; i++)
	{
		if (weight[i] == '0' || i == x)
			continue;

		if (cnt % 2 && (sum1 + i + 1 > sum2))
			temp = dfs(i, cnt+1, sum1 + i + 1, sum2);

		else if (cnt % 2 == 0 && (sum2 + i + 1 > sum1))
			temp = dfs(i, cnt+1, sum1, sum2 + i + 1);

		if (temp)
		{
			S.push(i+1);
			return 1;
		}
	}

	return 0;
}

int main()
{
	cin >> weight;

	cin >> m;

	bool temp;
	for (int i = 0; i < 10; i++)
	{
		if (weight[i] == '0')
			continue;

		if (dfs(i, 2, i+1, 0))
		{
			S.push(i+1);
			break;
		}
	}

	if (S.empty())
		cout << "NO\n";

	else
	{
		cout << "YES\n";

		while (!S.empty())
		{
			cout << S.top() << " ";
			S.pop();
		}

		cout << "\n";
	}

	return 0;
}