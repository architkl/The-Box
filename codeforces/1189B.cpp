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

bool mycomp(int a, int b)
{
	return (a > b);
}

int main()
{
	int n;
	cin >> n;

	vector <int> a(n);
	for (int i = 0; i < n; i++)
		cin >> a[i];

	sort(a.begin(), a.end(), mycomp);

	if (a[1] + a[2] <= a[0])
		cout << "NO\n";

	else
	{
		vector <int> b(n);
		b[0] = a[0];
		for (int i = 1; i < n-1; i++)
			b[i] = a[i+1];
		
		b[n-1] = a[1];

		cout << "YES\n";
		for (auto i : b)
			cout << i << " ";

		cout << "\n";
	}

	return 0;
}