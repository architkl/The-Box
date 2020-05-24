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
typedef pair <ll, ll> pll;

int find_free(vector <int> v, int x) {
	for (int i = 1; i < v.size(); i++) {
		if (v[i] == 0) {
			int j = i;
			while (j < v.size() && v[j] == 0) {
				if (j == i+x) break;
				j++;
			}

			if (j == i+x) return i;
		}
	}

	return -1;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int t, m;
	cin >> t >> m;

	vector <int> memory(m+1);
	map <int, int> id;
	string s;
	int x, num = 1;
	while (t--) {
		cin >> s;

		if (s == "alloc") {
			cin >> x;

			int free = find_free(memory, x);
			// cout << "F: " << free << "\n";

			if (free != -1) {
				id[num] = free;

				for (int i = 0; i < x; i++, free++) memory[free] = num;
				
				// cout << "id" << ": ";
				cout << num++ << "\n";
			}

			else cout << "NULL\n";
		}

		else if (s == "erase") {
			cin >> x;

			if (id.find(x) == id.end()) cout << "ILLEGAL_ERASE_ARGUMENT\n";

			else {
				// cout << "E: " << id[x] << "\n";
				for (int i = id[x]; i <= m && memory[i] == x; i++) memory[i] = 0;

				id.erase(x);
			}
		}

		else {
			for (auto i : id) {
				int j = 0;
				while (memory[i.second-j-1] == 0 && i.second-j-1 > 0) j++;

				// cout << i.first << ": " << i.second << " " << i.second-j << "\n";

				if (j > 0) {
					id[i.first] = i.second-j;

					for (int k = i.second; memory[k] == i.first; k++) {
						memory[k] = 0;
						memory[k-j] = i.first;
					}
				}
			}
		}
	}

	return 0;
}