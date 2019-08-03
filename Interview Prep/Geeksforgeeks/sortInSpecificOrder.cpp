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
#include <bitset>
#include <iomanip>
#include <climits>
#include <string>
#include <math.h>

using namespace std;

#define pb push_back
#define mp make_pair

typedef pair <int, int> pii;
typedef pair <int, pii> piii;
typedef unsigned long long ull;
typedef long long ll;

bool comp(int l, int r)
{
	return (l > r);
}

int main()
{
	int T;
	cin >> T;

	int N;
	while (T--)
	{
		cin >> N;

		vector <int> even, odd;
		int t;

		for (int i = 0; i < N; i++)
		{
			cin >> t;

			if (t % 2)
			{
				odd.pb(t);
				push_heap(odd.begin(), odd.end());
			}

			else
			{
				even.pb(t);
				push_heap(even.begin(), even.end(), comp);
			}
		}

		while (!odd.empty())
		{
			cout << odd[0] << " ";
			pop_heap(odd.begin(), odd.end());
			odd.pop_back();
		}

		while (!even.empty())
		{
			cout << even[0] << " ";
			pop_heap(even.begin(), even.end(), comp);
			even.pop_back();
		}

		cout << "\n";
	}
	/*
	bool (*fn_pt)(int, int) = comp;

	while (T--)
	{
		set <int> even;
		set <int, bool(*)(int, int)> odd(fn_pt);

		cin >> N;

		int t;
		for (int i = 0; i < N; i++)
		{
			cin >> t;

			if (t % 2)
				odd.insert(t);

			else
				even.insert(t);
		}

		for (auto i : odd)
			cout << i << " ";

		for (auto i : even)
			cout << i << " ";

		cout << "\n";
	}*/

	return 0;
}