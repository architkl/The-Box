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

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int d, sumTime;
	cin >> d >> sumTime;

	vector <int> minTime(d), maxTime(d);
	int mnsum = 0, mxsum = 0;
	for (int i = 0; i < d; i++) {
		cin >> minTime[i] >> maxTime[i];

		mnsum += minTime[i];
		mxsum += maxTime[i];
	}

	if (sumTime < mnsum || sumTime > mxsum) cout << "NO\n";

	else {
		vector <int> schedule(d);
		int time = 0;
		for (int i = 0; i < d; i++) {
			schedule[i] = minTime[i];
			time += minTime[i];
		}

		int day = 0, given;
		while (time != sumTime) {
			given = min(maxTime[day] - schedule[day], sumTime-time);
			schedule[day] += given;

			time += given;
			day++;
			day %= d;
		}

		cout << "YES\n";
		for (int i = 0; i < d; i++) cout << schedule[i] << " ";
		cout << "\n";
	}

	return 0;
}