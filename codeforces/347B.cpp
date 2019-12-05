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
	int n;
	cin >> n;

	vector <int> a(n);
	int res = 0;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
		
		if (i == a[i])
			res++;
	}
	
	bool f = 0;
	for (int i = 0; i < n; i++)
	{
		if (a[i] != i && a[a[i]] == i)
		{
			f = 1;
			break;
		}
	}
	
	if (f)
		cout << res+2 << "\n";
	
	else if (res == n)
		cout << res << "\n";

	else
		cout << res+1 << "\n";

	return 0;
}
