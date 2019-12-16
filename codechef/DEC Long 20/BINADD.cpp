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

string x, y;
int ans;

int binadd(string x, string y) {
	int cnt = 0;
	bitset <(int)8> a(x), b(y), u, v;

	while (b.any()) {
		// cout << a.to_string().erase(0, min(a.to_string().find_first_not_of('0'), a.to_string().size()-1)) << " " << b.to_string().erase(0, min(a.to_string().find_first_not_of('0'), b.to_string().size()-1)) << "\n";
		// cout << a.to_ulong() << " " << b.to_ulong() << "\n";
		u = a ^ b;
		v = a & b;
		a = u;
		b = (v << 1);
		cnt++;
	}
	// cout << "\n";

	return cnt;
}

/*int solve(string x, string y) {
	int cnt = 0;
	string sum = "", str = "";

	bool f = 0;
	for (int i = 0; i < y.length(); i++) if (y[i] == '1') f = 1;
	if (!f) return 0;

	for (int i = 0; i < x.length(); i++) if (x[i] == '1') f = 1;
	if (!f) return 1;

	reverse(x.begin(), x.end());
	reverse(y.begin(), y.end());

	if (x.length() > y.length()) for (int i = y.length(); i < x.length(); i++) y += "0";
	else for (int i = x.length(); i < y.length(); i++) x += "0";

	cout << x << "\n" << y << "\n";

	bool c = 0;
	for (int i = 0; i < x.length(); i++) {
		if (x[i]-48+y[i]-48+c == 1 || x[i]-48+y[i]-48+c == 3) sum += "1";
		else sum += "0";

		c = (x[i]-48+y[i]-48+c == 3) || (x[i]-48+y[i]-48+c == 2);
		cnt += c;

		str += (((x[i]-48)^(y[i]-48)) + 48);
	}

	if (c) sum += "1";

	// reverse(str.begin(), str.end());
	// cout << str << "\n";

	// reverse(sum.begin(), sum.end());
	// cout << sum << "\n";

	// for (int i = 0; i < str.length(); i++) cnt += (sum[i] != str[i]);
	// cnt += 1+c;

	return cnt;
}*/

void rec(vector <int> carry) {
	if (carry.size() == 0) return;

	ans++;
	vector <int> new_carry;
	for (int i = 0; i < carry.size(); i++) {
		if (x[carry[i]]-48+y[carry[i]]-48 == 1) new_carry.pb(carry[i]+1);
	}

	rec(new_carry);
}

int solve() {
	ans = 0;
	vector <int> carry;

	bool f = 0;
	for (int i = 0; i < y.length(); i++) if (y[i] == '1') f = 1;
	if (!f) return 0;

	for (int i = 0; i < x.length(); i++) if (x[i] == '1') f = 1;
	if (!f) return 1;

	reverse(x.begin(), x.end());
	reverse(y.begin(), y.end());

	if (x.length() > y.length()) for (int i = y.length(); i < x.length(); i++) y += "0";
	else for (int i = x.length(); i < y.length(); i++) x += "0";

	for (int i = 0; i < x.length(); i++) if (x[i]-48+y[i]-48 == 2) carry.pb(i+1);
	
	ans++;
	rec(carry);

	return ans;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int T;
	cin >> T;

	// string A, B = "";
	// for (int i = 0; i < 1e5-1; i++) B += "1";

	// for (int i = 0; i < 16; i++) {
	// 	bitset <4> x(i);
	// 	string a = (x.to_string()).erase(0, min(x.to_string().find_first_not_of('0'), x.to_string().size()-1));
	// 	for (int j = 0; j <= i; j++) {
	// 		bitset <4> y(j);
	// 		string b = (y.to_string()).erase(0, min(y.to_string().find_first_not_of('0'), y.to_string().size()-1));
	// 		cout << a << " " << b << ": " << binadd(a, b) << "\n";
	// 	}
	// 	cout << "\n";
	// }

	while (T--) {
		cin >> x >> y;

		// cout << binadd(x, y) << "\n\n";
		cout << solve() << "\n";
	}

	return 0;
}