/*
Author: architkl
Language: C++ 14
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <unordered_map>
#include <queue>
#include <set>
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

	vector <int> psy(n), death(n);
	for (int i = 0; i < n; i++)
		cin >> psy[i];

	stack <int> S;
	S.push(psy[0]);
	death[0] = -1;
	for (int i = 1; i < n; i++)
	{
	}

	return 0;
}

/*
10 9 7 8 6 5 3 4 2 1

-1 1 1 2 1 1 1 2 1 1

10 9 8 6 5 4 2 1