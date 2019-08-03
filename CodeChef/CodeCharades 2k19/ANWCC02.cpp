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

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int N, M;
	cin >> N >> M;

	vector <int> c(N), k(M);
	for (int i = 0; i < N; i++)
		cin >> c[i];

	for (int i = 0; i < M; i++)
		cin >> k[i];

	int ans = 0, temp;
	for (int i = 0; i < M; i++)
		ans += c[i] * k[i];

	temp = ans;

	int l = 1, r = M;
	while (r < N)
	{
		temp -= (c[l-1] * k[l-1]);
		temp += (c[r] * k[r]);

		if (temp > ans)
			ans = temp;
	}

	cout << ans << "\n";

	return 0;
}