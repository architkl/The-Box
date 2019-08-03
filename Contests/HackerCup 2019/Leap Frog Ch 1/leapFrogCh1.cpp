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

	int T, i = 0;
	cin >> T;

	string s;
	int c;
	while (T--)
	{
		cin >> s;

		i++;
		cout << "Case #" << i << ": ";

		c = count(s.begin(), s.end(), 'B');

		if (c >= s.length() / 2 && c != s.length()-1)
			cout << "Y\n";

		else
			cout << "N\n";
	}

	return 0;
}