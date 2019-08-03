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
#include <iomanip>
#include <climits>
#include <string>
#include <math.h>

using namespace std;

#define pb push_back
#define mp make_pair

typedef pair <int, int> pii;
typedef unsigned long long ull;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;

	string s;
	cin >> s;

	int f = 0;
	for (int i = 1; i < n; i++)
	{
		if (s[i] < s[i-1])
		{
			f = 1;
			cout << "YES\n" << i << " " << i+1 << "\n";
			break;
		}
	}

	if (!f)
		cout << "NO\n";

	return 0;
}