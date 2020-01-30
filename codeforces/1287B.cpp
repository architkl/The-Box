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
	int n, k;
	cin >> n >> k;

	vector <string> v(n);
	unordered_map <string, bool> ex;
	for (int i = 0; i < n; i++) {
		cin >> v[i];

		ex[v[i]] = 1;
	}

	int ans = 0;
	for (int i = 0; i < n; i++) {
		for (int j = i+1; j < n; j++) {
			string temp = "";
			for (int l = 0; l < k; l++) {
				if (v[i][l] == v[j][l]) temp += v[i][l];

				else {
					if (v[i][l] == 'S' && v[j][l] == 'E') temp += 'T';
					else if (v[i][l] == 'S' && v[j][l] == 'T') temp += 'E';
					else if (v[i][l] == 'E' && v[j][l] == 'T') temp += 'S';
					else if (v[i][l] == 'E' && v[j][l] == 'S') temp += 'T';
					else if (v[i][l] == 'T' && v[j][l] == 'E') temp += 'S';
					else temp += 'E';
				}
			}

			if (ex[temp]) {
				// charout << v[i] << " " << v[j] << " " << temp << "\n";
				ans++;
			}
		}
	}

	cout << ans/3 << "\n";

	return 0;
}