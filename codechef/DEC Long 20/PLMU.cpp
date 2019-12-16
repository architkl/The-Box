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
	int T;
	cin >> T;

	int N;
	while (T--) {
		cin >> N;

		int tmp, cnt_0 = 0, cnt_2 = 0;
		for (int i = 0; i < N; i++) {
			cin >> tmp;

			if (tmp == 0) cnt_0++;
			else if (tmp == 2) cnt_2++;
		}

		cout << (cnt_0 * (cnt_0-1)) / 2 + (cnt_2 * (cnt_2-1)) / 2 << "\n";
	}

	return 0;
}