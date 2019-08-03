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

	string s;
	cin >> s;

	int n = s.length();

	int cnt = 0;
	for (int i = 0; i < n; i++)
		if (s[i] == 'a')
			cnt++;

	if (n/2 >= cnt)
		cout << 2*cnt - 1 << "\n";

	else
		cout << n << "\n";

	return 0;
}