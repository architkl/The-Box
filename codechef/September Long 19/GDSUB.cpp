/*
Author: architkl
Language: C++ 14
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <unordered_map>
#include <queue>
#include <set>
#include <climits>
#include <string>
#include <math.h>

using namespace std;

#define pb push_back
#define mp make_pair

typedef pair <int, int> pii;
typedef unsigned long long ull;

int cnt = 0;

void seq(vector <int> A, set <int> S, int pos, int K) {
	if (pos == A.size()) {
		if (S.size() > K)
			return;

		cnt++;
		for (auto i : S)
			cout << i << " ";
		cout << "\n";

		return;
	}

	// cout << pos << " " << A.size() << "\n";

	seq(A, S, pos+1, K);
	if (S.find(A[pos]) == S.end()) {
		S.insert(A[pos]);
		seq(A, S, pos+1, K);
	}
}

int main()
{
	int N, K;
	cin >> N >> K;

	unordered_map <int, int> freq;
	vector <int> A(N);
	for (int i = 0; i < N; i++) {
		cin >> A[i];

		freq[A[i]]++;
	}

	set <int> S;

	seq(A, S, 0, K);

	cout << "\n" << cnt << "\n";

	for (auto i : freq) {
		cout << i.first << ": " << i.second << "\n";
	}

	return 0;
}