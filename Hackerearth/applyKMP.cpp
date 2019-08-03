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

void calc(vector <int> &lps, string P)
{
	lps[0] = 0;

	int i = 1, j = 0;
	while (i < P.length())
	{
		if (P[i] == P[j])
		{
			lps[i] = j + 1;
			i++;
			j++;
		}

		else if (j == 0)
		{
			lps[i] = 0;
			i++;
		}

		else
			j = lps[j-1];
	}
}

int main()
{
	string P, T;
	cin >> P >> T;

	vector <int> lps(P.length());

	calc(lps, P);

	/*for (auto i : lps)
		cout << i << " ";
	cout << "\n";*/

	int cnt = 0, i = 0, j = 0;
	while (i < T.length())
	{
		if (T[i] == P[j])
		{
			while (j < P.length() && i < T.length() && T[i] == P[j])
			{
				// cout << j << " " << i << "\n";
				i++;
				j++;
			}

			if (j == P.length())
				cnt++;

			j = lps[j-1];
		}

		else
			i++;
	}

	cout << cnt << "\n";

	return 0;
}