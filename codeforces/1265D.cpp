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
	int a, b, c, d;

	cin >> a >> b >> c >> d;

	if ((a > b+1) || (d > c+1)) cout << "NO\n";

	else if ((a == b+1 && c+d != 0) || (d == c+1 && a+b != 0)) cout << "NO\n";

	else {
		string p1 = "", p2 = "";
		for (int i = 0; i < min(a,b); i++) p1 += "01";
		b -= a;
		if (b < 0) {
			p1 += "0";
			b = 0;
		}

		for (int i = 0; i < min(c,d); i++) p2 += "23";
		c -= d;
		if (c < 0) {
			p2 = "3" + p2;
			c = 0;
		}

		for (int i = 0; i < min(b, c); i++) p1 += "21";

		int tmp = min(b, c);
		b -= tmp;
		c -= tmp;

		if (b == 1 || c == 1 || (b == 0 && c == 0)) {
			if (b == 1) p1 = "1" + p1;
			else if (c == 1) p2 += "2";

			cout << "YES\n";
			for (auto i : p1) cout << i << " ";
			for (auto i : p2) cout << i << " ";
			cout << "\n";
		}

		else cout << "NO\n";
	}

	return 0;
}
/*

010101  2121   232323

*/