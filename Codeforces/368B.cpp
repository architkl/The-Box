#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int N_MAX = 100005;

vector <int> POST(N_MAX);
vector <int> cnt(N_MAX);

void init(vector <int> a, int n)
{
	POST[n-1] = 1;
	cnt[a[n-1]]++;
	for (int i = n-2; i >= 0; i--)
	{
		POST[i] = POST[i+1];

		if (cnt[a[i]])
			continue;

		cnt[a[i]]++;
		POST[i]++;
	}
}

int main()
{
	int n, m;
	cin >> n >> m;

	vector <int> a(n), l(m);
	for (int i = 0; i < n; i++)
		cin >> a[i];

	for (int i = 0; i < m; i++)
	{
		cin >> l[i];
		l[i]--;
	}

	init(a, n);

	for (int i = 0; i < m; i++)
		cout << POST[l[i]] << "\n";

	return 0;
}