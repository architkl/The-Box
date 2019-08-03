/*
Author: architkl
Language: C++ 11
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <math.h>

using namespace std;

#define pb push_back
#define mp make_pair

typedef pair <int, int> pii;
typedef unsigned long long ull;

void func(vector <int> v, int k, int last)
{
	//cout << last << "\n";

	// for (auto i : v)
	// 	cout << i << " ";
	// cout << "\n\n";

	int n = v.size();
	vector <int> d(n);
	for (int i  = 0; i < n; i++)
		d[i] = v[i] - k;

	// for (auto i : d)
	// 	cout << i << " ";
	// cout << "\n\n";

	int i = 0;
	while (d[i] <= 0 && i < last)
		i++;

	int sum = 0;
	for (i; i < last; i++)
	{
		if (sum + d[i] > d[last])
			break;

		sum += d[i];
		v[i] = k;
		v[last] -= d[i];
	}

	//cout << last << " " << v[last] << "\n\n";

	if (i == last)
	{
		v[n-1] -= (v[last] - k);
		v[last] = k;
		int sum2 = 0;
		for (int j = 0; j < n; j++)
		{
			// cout << v[j] << " " ;
			sum2 += v[j];
		}
		// cout << "\n";

		cout << sum2 << "\n";
	}

	else
	{
		sort(v.begin(), v.end());
		func(v, k, last);
	}
}

int main()
{
	// ios_base::sync_with_stdio(false);
	// cin.tie(NULL);

	int T;
	cin >> T;

	int n, k;
	ull sum;
	for (int i = 0; i < T; i++)
	{
		cin >> n >> k;

		vector <int> A(n);
		for (int j = 0; j < n; j++)
			cin >> A[j];

		sort(A.begin(), A.end());

		int diff = 0;
		for (int j = 0; j < n; j++)
		{
			diff += A[j] - k;
		}
	}

	return 0;
}