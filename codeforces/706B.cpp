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
#include <cmath>
 
using namespace std;
 
#define pb push_back
#define mp make_pair
 
typedef pair <int, int> pii;
typedef pair <int, pii> piii;
typedef unsigned long long ull;
typedef long long ll;
 
int main()
{
	int n;
	cin >> n;
 
	auto cmp = [](pii a, pii b) { return a.first < b.first; };
	set <pii, decltype(cmp)> x_set(cmp);
	vector <int> x(n);
	for (int i = 0; i < n; i++)
		cin >> x[i];
	
	sort(x.begin(), x.end());
 
	for (int i = 0; i < n; i++)
		x_set.insert(mp(x[i], i));
 
	x_set.insert(mp(INT_MAX, n));
 
	int q;
	cin >> q;
 
	int m;
	while (q--)
	{
		cin >> m;
 
		cout << (x_set.upper_bound(mp(m, 0)))->second << "\n";
	}
 
	return 0;
}