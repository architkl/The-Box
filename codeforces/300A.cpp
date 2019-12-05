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
typedef unsigned long long ull;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;

	vector <int> pos, neg, zer;
	int t;
	for (int i = 0; i < n; i++)
	{
		cin >> t;

		t > 0 ? pos.pb(t) : t == 0 ? zer.pb(t) : neg.pb(t);
	}

	if (!pos.size())
	{
		if (neg.size() % 2)
		{
			cout << 1 << " " << neg[0] << "\n";

			cout << neg.size()-1 << " ";
			for (int i  = 1; i < neg.size(); i++)
				cout << neg[i] << " ";
			
			cout << "\n" << zer.size() << " ";
			for (auto i : zer)
				cout << i << " ";
			cout << "\n";
		}

		else
		{
			cout << 1 << " " << neg[0] << "\n";

			cout << neg.size()-2 << " ";
			for (int i = 2; i < neg.size(); i++)
				cout << neg[i] << " ";

			cout << "\n" << zer.size()+1 << " " << neg[1] << " ";
			for (auto i : zer)
				cout << i << " ";
			cout << "\n";
		}
	}

	else
	{
		if (neg.size() % 2)
		{
			cout << neg.size() << " ";
			for (auto i : neg)
				cout << i << " ";

			cout << "\n" << pos.size() << " ";
			for (auto i : pos)
				cout << i << " ";

			cout << "\n" << zer.size() << " ";
			for (auto i : zer)
				cout << i << " ";
			cout << "\n";
		}

		else
		{
			cout << neg.size()-1 << " ";
			for (int i = 1; i < neg.size(); i++)
				cout << neg[i] << " ";

			cout << "\n" << pos.size() << " ";
			for (auto i : pos)
				cout << i << " ";

			cout << "\n" << zer.size()+1 << " " << neg[0] << " ";
			for (auto i : zer)
				cout << i << " ";
			cout << "\n";
		}
	}

	return 0;
}