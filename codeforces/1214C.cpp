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

int main() {
	int n;
	cin >> n;

	string s;
	cin >> s;

	stack <char> S;
	int miss = 0;
	for (int i = 0; i < n; i++) {
		if (s[i] == '(')
			S.push(s[i]);

		else if (!S.empty())
			S.pop();

		else
			miss++;
	}

	if ((S.size() == 1 && miss == 1) || (S.size() == 0 && miss == 0))
		cout << "YES\n";

	else
		cout << "NO\n";

	return 0;
}