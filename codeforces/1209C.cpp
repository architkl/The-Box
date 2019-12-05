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
	int t;
	cin >> t;

	int n;
	string a;
	while (t--) {
		cin >> n;

		cin >> a;
		// a = to_string(t);
		// n = a.size();

		// cout << "\n\n" << a << "\n";

		vector <int> color(n);
		bool flag = true;
		int ptr1 = -1, ptr2 = -1, col = 1, temp1 = -1, temp2 = -1;
		for (int i = 0; i < 10; i++) {
			// cout << i << " " << ptr1 << " " << ptr2 << "\n";
			for (int j = 0; j < n; j++) {
				if (a[j]-48 != i)
					continue;

				if (j < ptr1) {
					flag = false;
					break;
				}

				else if (ptr2 == -1) {
					color[j] = 1;
					temp2 = j;
				}

				else if (j < ptr2) {
					color[j] = 2;
					temp2 = INT_MAX;
					temp1 = j;
				}

				else {
					color[j] = 1;
					temp2 = max(temp2, j);
				}
			}

			ptr2 = max(ptr2, temp2);
			ptr1 = temp1;
		}
/*
		if (flag) {
			int m1 = -1, m2 = 10;
			for (int i = 0; i < n; i++) {
				if (color[i] == 1)
					m1 = max(m1, a[i]-48);

				else
					m2 = min(m2, a[i]-48);
			}

			if (m2 < m1)
				cout << a << "\n";
		}*/

		if (!flag)
			cout << "-\n";

		else {
			for (auto i : color)
				cout << i;

			cout << "\n";
		}
	}

	return 0;
}