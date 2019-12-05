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

	vector <int> a(n);
	for (int i = 0; i < n; i++)
		cin >> a[i];

	unordered_map <int, bool> col;
	int c = 0;
	sort(a.begin(), a.end());

	for (int i = 0; i < n; i++) {
		if (!col[a[i]])
			c++;

		else
			continue;
		
		for (int j = i; j < n; j++) {
			if (!col[a[j]] && a[j] % a[i] == 0) {
				col[a[j]] = true;
			}
		}
	}

	cout << c << "\n";

	return 0;
}