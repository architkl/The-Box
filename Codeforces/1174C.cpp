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
	// ios_base::sync_with_stdio(false);
	// cin.tie(NULL);

	int n;
	cin >> n;

	vector <int> a(n+1, -1);
	int cur_n = 1;
	for (int i = 2; i <= n; i++)
	{
		if (a[i] != -1)
			continue;

		for (int j = i; j <= n; j += i)
		{
			if (a[j] != -1)
				continue;

			a[j] = cur_n;
		}

		cur_n++;
	}

	/*for (int i = 2; i <= n; i++)
	{
		for (int j = i+1; j <= n; j++)
		{
			if (__gcd(i, j) == 1 && a[i] == a[j])
				cout << "P\n";
		}
	}*/

	for (int i = 2; i <= n; i++)
		cout << a[i] << " ";
	cout << "\n";
	/*for (int i = 2; i <= n; i++)
		cout << i << " ";
	cout << "\n";*/

	return 0;
}