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
	int n, k;
	cin >> n >> k;

	vector <int> h(n);
	for (int i = 0; i < n; i++)
		cin >> h[i];

	vector <int> sum(n);
	sum[0] = h[0];
	for (int i = 1; i < k; i++)
		sum[i] = sum[i-1] + h[i];

	int res = 0, mn = sum[k-1];
	for (int i = k; i < n; i++)
	{
		sum[i] = sum[i-1] - h[i-k] + h[i];

		if (sum[i] < mn)
		{
			res = i-k+1;
			mn = sum[i];
		}
	}
	
	cout << res+1 << "\n";

	return 0;
}