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
	ll n, k;
	cin >> n >> k;

	vector <ll> div2;
	int cnt = 0;
	bool f = 0;
	for (int i = 1; i <= sqrt(n); i++)
	{
		if (n % i == 0)
		{
			cnt++;
			div2.pb(n/i);
		}
		
		if (cnt == k)
		{
			cout << i << "\n";
			f = 1;
			break;
		}
	}
	
	if (!f)
	{
		int temp = sqrt(n);
		if (sqrt(n) == temp)
			div2.pop_back();
		
		if (cnt + div2.size() >= k)
			cout << div2[div2.size()-k+cnt] << "\n";
		 
		 else
		 	cout << "-1\n";
	}
	
	return 0;
}
