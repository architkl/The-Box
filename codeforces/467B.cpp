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

	int n, m, k;
	cin >> n >> m >> k;

	vector <int> army(m+1);
	for (int i = 0; i <= m; i++)
		cin >> army[i];

	int res = 0;
	for (int i = 0; i < m; i++)
		if ((bitset <32> (army[i] ^ army[m])).count() <= k)
			res++;
	
	cout << res << "\n";

	return 0;
}