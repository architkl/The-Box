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

bool mycomp(pii a, pii b)
{
	return (a.second < b.second);
}

int main()
{
	// ios_base::sync_with_stdio(false);
	// cin.tie(NULL);

	int n;
	cin >> n;
	
	vector <int> a(n);
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];

		if (a[i] >= 0)
			a[i] = -a[i] - 1;
	}

	if (a.size() % 2)
	{
		int idx = 0;
		for (int i = 1; i < n; i++)
			if (a[i] < a[idx])
				idx = i;

		a[idx] = -a[idx] - 1;
	}

	for (auto i : a)
		cout << i << " ";
	cout << "\n";

	return 0;
}