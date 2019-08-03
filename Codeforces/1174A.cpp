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

	int n;
	cin >> n;

	vector <int> a(2*n);
	for (int i = 0; i < 2*n; i++)
		cin >> a[i];

	sort(a.begin(), a.end());

	int sum1 = 0, sum2 = 0;
	for (int i = 0; i < n; i++)
	{
		sum1 += a[i];
		sum2 += a[2*n-i-1];
	}

	if (sum1 == sum2)
		cout << -1 << "\n";

	else
	{
		for (auto i : a)
			cout << i << " ";
		cout << "\n";
	}
c
	return 0;
}