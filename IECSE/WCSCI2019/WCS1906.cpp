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
	int N;
	cin >> N;

	vector <double> A(N);
	for (int i = 0; i < N; i++) cin >> A[i];

	double mn = INT_MAX;
	int idx;
	for (int i = 0; i < N; i++) {
		if (ceil((A[i]-i) / N)*N + i < mn) {
			mn = min(mn, ceil((A[i]-i) / N)*N + i);
			idx = i;
		}
	}

	cout << idx+1 << "\n";

	return 0;
}