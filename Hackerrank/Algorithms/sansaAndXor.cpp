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

	int t;
	cin >> t;

	int n;
	while (t--)
	{
		cin >> n;

		vector <int> arr(n);
		for (int i = 0; i < n; i++)
			cin >> arr[i];

		int res = 0;
		for (int i = 0; i < n; i++)
			if ((i+1)*(n-i) % 2)
				res ^= arr[i];
		
		cout << res << "\n";
	}

	return 0;
}