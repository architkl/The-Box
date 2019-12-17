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
#include <unordered_set>
#include <bitset>
#include <iomanip>
#include <climits>
#include <string>
#include <cstring>
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
	for (int i = 0; i < n; i++) {
		cin >> s;

		int sum = 0, even = 0;
		bool zero = false;
		for (int j = 0; j < s.length(); j++) {
			sum += s[j]-48;

			zero |= (s[j] == '0');
			even += (((s[j]-48) % 2) == 0);
		}

		if (sum%3 == 0 && zero && even > 1) cout << "red\n";
		else cout << "cyan\n";
	}

	return 0;
}