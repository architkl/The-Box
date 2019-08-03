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

const int sieve_max = 1e7;

long long int comp(vector <long long int> v, long long int x)
{
	long long int sum = 0;
	for (auto i : v)
	{
		if (x > i)
			continue;

		sum += i - x;
	}

	return sum;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	long long int n, r;
	cin >> n >> r;

	vector <long long int> C(n);
	long long int mx = 0;
	for (int i = 0; i < n; i++)
	{
		cin >> C[i];

		if (C[i] > mx)
			mx = C[i];
	}

	long long int l = 0, h = mx, mid;
	while (l <= h)
	{
		mid = (l + h) / 2;
		// cout << mid << "\n";

		if (comp(C, mid) >= r)
			l = mid+1;

		else
			h = mid-1;
	}

	// cout << h << "\n";

	while (comp(C, h) >= r)
		h++;
	h--;

	if (comp(C, h) >= r)
		cout << h << "\n";

	else
		cout << mid << "\n";

	return 0;
}