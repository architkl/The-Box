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

	vector <int> a(n);
	int odd = 0, even = 0;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];

		odd += a[i] % 2;
		even += !(a[i] % 2);
	}

	if (odd && even)
		sort(a.begin(), a.end());

	for (auto i : a)
		cout << i << " ";
	cout << "\n";

	return 0;
}