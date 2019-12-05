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
#include <cmath>

using namespace std;

#define pb push_back
#define mp make_pair

typedef pair <int, int> pii;
typedef pair <int, pii> piii;
typedef unsigned long long ull;
typedef long long ll;

const int N_MAX = 1000 * 100 + 5;

vector < vector <int> > freq(26, vector <int> (N_MAX));

void pre(string s) {
	// for (int j = 0; j < 26; j++) freq[j][0] = (s[0] == 'a'+j);

	for (int i = 1; i <= s.length(); i++) {
		for (int j = 0; j < 26; j++) {
			freq[j][i] = freq[j][i-1];

			if (s[i-1] == j+'a') freq[j][i]++;
		}
	}
}

bool k_dom(string s, int k) {
	bool flag;
	for (int i = 'a'; i <= 'z'; i++) {
		flag = 1;
		for (int j = k; j <= s.length(); j++) {
			if ((freq[i-'a'][j] - freq[i-'a'][j-k]) == 0)  {
				flag = 0;
				// cout << j << ": " << freq[i-'a'][j] << "\n" << j-k << ": " << freq[i-'a'][j-k] << "\n";
				// cout << (char)i << " rejected for len " << k << "\n";
				break;
			}
		}

		if (flag) return true;
	}

	return false;
}

int main() {
	// ios_base::sync_with_stdio(false);
	// cin.tie(NULL);
	// cout.tie(NULL);

	string s;
	cin >> s;

	pre(s);
	/*for (int i = 0; i < 3; i++) {
		for (int j = 0; j <= s.length(); j++) cout << freq[i][j] << " ";
		cout << "\n";
	}*/

	int l = 1, h = 1000 * 100, mid;
	while (l < h) {
		mid = (l + h) / 2;

		// cout << l << " " << mid << " " << h << "\n";

		if (k_dom(s, mid)) h = mid;

		else l = mid+1;
	}

	cout << l << "\n";

	return 0;
}