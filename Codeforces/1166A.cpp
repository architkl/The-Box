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

int C2(int x)
{
	return x*(x-1) / 2;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;

	string s;
	int freq[26] = {};
	for (int i = 0; i < n; i++)
	{
		cin >> s;

		freq[s[0]-97]++;
	}

	int ans = 0;
	for (int i = 0; i < 26; i++)
	{
		ans += C2(freq[i] / 2) + C2(freq[i] - freq[i]/2);
	}

	cout << ans << "\n";

	return 0;
}