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
 
	vector <int> a(n), pre(n);
	for (int i = 0; i < n; i++)
		cin >> a[i];
	
	pre[0] = a[0];
	for (int i = 1; i < n; i++)
		pre[i] += pre[i-1] + a[i];
 
	int m;
	cin >> m;
 
	int w, l, h, mid;
	for (int i = 0; i < m; i++)
	{
		cin >> w;
 
		l = 0, h = n-1;
		while (l <= h)
		{
			mid = (l + h) / 2;
			// cout << l << " " << mid << " " << h << "\n";
 
			if (pre[mid] <= w)
				l = mid + 1;
 
			else
				h = mid - 1;
		}
 
		cout << ((pre[max(h,0)] >= w) ? max(h+1,1) : l+1) << "\n";
	}
 
	return 0;
}