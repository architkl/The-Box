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

const int K = 1e9+7;

int main() {
	int n, m;
	cin >> n >> m;

	vector < vector < vector <int> > > dp(m+1, vector < vector <int> > (n+1, vector <int> (n+1)));
	for (int i = 1; i <= m; i++) {
		for (int j = 1; j <= n; j++) {
			for (int k = j; k <= n; k++) {
				
			}
		}
	}

	return 0;
}