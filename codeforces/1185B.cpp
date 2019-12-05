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
	// ios_base::sync_with_stdio(false);
	// cin.tie(NULL);

	int n;
	cin >> n;

	unordered_map <char, int> freq1, freq2;
	bool f;

	string s, t;
	while (n--)
	{
		cin >> s >> t;

		if (s.length() > t.length())
		{
			cout << "NO\n";
			continue;
		}

		f = 1;

		int j = 0, count;
		for (int i = 0; i < s.length(); i++)
		{
			count = 1;
			while (i < s.length() && s[i] == s[i+1])
			{
				count++;
				i++;
			}

			while (count--)
			{
				if (j == t.length() || t[j] != s[i])
				{
					f = 0;
					break;
				}

				j++;
			}

			if (!f)
				break;

			while (j < t.length() && t[j] == t[j-1])
				j++;
		}

		if (j != t.length())
			f = 0;

		f ? cout << "YES\n" : cout << "NO\n";
	}

	return 0;
}