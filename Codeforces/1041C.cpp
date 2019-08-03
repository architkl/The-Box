/*
Author: architkl
Language: C++ 11
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <string>
#include <math.h>

using namespace std;

#define push_back pb
#define for(n) for(int ii = 0; ii < n; ii++)

typedef pair <int, int> pii;

int main()
{
	int n, m , d;
	cin >> n >> m >> d;

	vector <int> a(n);
	multiset <int> myset;
	for(n)
	{
		cin >> a[ii];
		myset.insert(a[ii]);
	}
	
	map <int, int> mymap;
	int day = 1;
	multiset <int>::iterator cur, nxt;
	while (!myset.empty())
	{
		cur = myset.begin();
		mymap[*cur] = day;
		nxt = myset.lower_bound(*cur + d + 1);
		myset.erase(cur);

		while (nxt != myset.end())
		{
			mymap[*nxt] = day;
			cur = nxt;
			nxt = myset.lower_bound(*cur + d + 1);
			myset.erase(cur);
		}

		day++;
	}

	cout << day - 1 << "\n";

	for(n)
		cout << mymap[a[ii]] << " ";

	return 0;
}