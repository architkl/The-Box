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
	int n;
	cin >> n;

	vector <int> arr(n);
	for (int i = 0; i < n; i++) cin >> arr[i];

	vector < vector <int> > ans(n, vector <int> (n, -1));
	for (int i = 0; i < n; i++) {
		priority_queue <int> mxh;
		priority_queue <int, vector <int>, greater<int>> mnh;

		for (int j = i; j < n; j++) {
			if (mxh.size() == 0) mxh.push(arr[j]);

			else if (mxh.size() == mnh.size()) {
				if (arr[j] <= mnh.top()) mxh.push(arr[j]);
				else {
					int temp = mnh.top();
					mnh.pop();
					mnh.push(arr[j]);
					mxh.push(temp);
				}
			}

			else {
				if (arr[j] >= mxh.top()) mnh.push(arr[j]);
				else {
					int temp = mxh.top();
					mxh.pop();
					mxh.push(arr[j]);
					mnh.push(temp);
				}
			}

			ans[i][j] = mxh.top();
		}
	}

	/*for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << ans[i][j] << " ";
		}
		cout << "\n";
	}*/

	int q;
	cin >> q;

	int a, b;
	while (q--) {
		cin >> a >> b;

		a--;
		b--;

		cout << ans[a][b] << "\n";
	}

	return 0;
}