/*
Author: architkl
Language: C++ 14
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <unordered_map>
#include <queue>
#include <set>
#include <climits>
#include <string>
#include <math.h>

using namespace std;

#define pb push_back
#define mp make_pair

typedef pair <int, int> pii;
typedef unsigned long long ull;

const int K = 998244353;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;

	string s;
	cin >> s;

	ull l = 1, r = 1;
	for (int i = 1; i < s.length(); i++)
	{
		if (s[i] == s[i-1])
			l++;

		else
			break;
	}

	for (int i = s.length()-2; i >= 0; i--)
	{
		if (s[i] == s[i+1])
			r++;

		else
			break;
	}

	s[0] == s[s.length()-1] ? cout << ((l+1) * (r+1)) % K << "\n" : cout << l + r + 1 << "\n";

	return 0;
}

/*
abaa

a 3
b 1

a 0 2 3

b 1
*/