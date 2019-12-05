/*
Author: architkl
Language: C++ 11
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

const int N_MAX = 2e5 + 5;

int freq[N_MAX] = {};

int sum(int val)
{
	int S = 0;
	for (int i = 1; i < N_MAX; i++)
		S += freq[i] / val;

	return S;
}

int b_search(int n, int k)
{
	int low = 1, high = n, mid = 0, ans, s = 0;

	while (low <= high)
	{
		mid = (low + high) / 2;

		s = sum(mid);

		if (s >= k)
		{
			ans = mid;
			low = mid + 1;
		}
		
		else
			high = mid - 1;
	}

	return ans;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, k;
	cin >> n >> k;

	vector <int> s(n);
	for (int i = 0; i < n; i++)
	{
		cin >> s[i];

		freq[s[i]]++;
	}

	// for (int i = 0; i < 2e5; i++)
	// 	if (freq[i] > 0)
	// 		cout << i << " " << freq[i] << "\n";

	vector <int> t;
	int copies = b_search(n, k);
	// cout << copies << "\n";
	for (int i = 1; i < N_MAX; i++)
	{
		if (freq[i]/copies >= 1)
		{
			int j = freq[i]/copies;
			while (j--)
			{
				t.pb(i);

				if (t.size() == k)
					break;
			}
		}

		if (t.size() == k)
			break;
	}

	for (auto j : t)
		cout << j << " ";

	cout << "\n";

	return 0;
}