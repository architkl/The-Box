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
	int L, R;
	cin >> L >> R;

	// vector <int> X(R), Y(R);
	int x, y;
	vector <int> line(L+1, -1);
	for (int i = 0; i < R; i++) {
		cin >> x >> y;

		line[x] *= (-1);
		line[y] *= (-1);
	}

	return 0;
}