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
#include <cmath>

using namespace std;

#define pb push_back
#define mp make_pair

typedef pair <int, int> pii;
typedef pair <int, pii> piii;
typedef unsigned long long ull;
typedef long long ll;

int main()
{
	string s;
	cin >> s;

	int cnt = 0;
	for (int i = 0; i < s.length(); i++)
		cnt += (s[i] == '1');

	if (cnt == 0)
		cout << "0\n";

	else
		cout << (cnt == 1 ? s.length() / 2 : ceil(s.length() / 2.0)) << "\n";

	return 0;
}