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
#include <iomanip>
#include <climits>
#include <string>
#include <math.h>

using namespace std;

#define pb push_back
#define mp make_pair

typedef pair <int, int> pii;
typedef unsigned long long ull;

/*int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;

	unordered_map <int, int> freq;
	vector <int> v;
	int t;
	for (int i = 0; i < n; i++)
	{
		cin >> t;

		if (freq[t])
			continue;

		freq[t] = 1;
		v.pb(abs(t));
	}

	sort(v.begin(), v.end());

	vector <int>::iterator it;
	long long int ans = 0, l = 0, r = 1;
	while (l < n)
	{
		while (r < n && v[r] <= 2*v[l])
			r++;

		ans += r-l-1;
		l++;
	}

	cout << ans << "\n";

	return 0;
}*/

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;

	vector <int> v(n);
	for (int i = 0; i < n; i++)
	{
		cin >> v[i];

		v[i] = abs(v[i]);
	}

	sort(v.begin(), v.end());

	vector <int>::iterator it;
	long long int ans = 0, l = 0, r = 1;
	while (l < n)
	{
		while (r < n && v[r] <= 2*v[l])
			r++;

		ans += r-l-1;
		l++;
	}

	cout << ans << "\n";

	return 0;
}