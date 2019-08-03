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

bool comp(pii a, pii b)
{
	return (a.second > b.second);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int N;
	cin >> N;

	vector <pii> TL(N);
	for (int i = 0; i < N; i++)
		cin >> TL[i].first >> TL[i].second;

	sort(TL.begin(), TL.end());

	vector <pii> wait;
	int it = 0;
	wait.pb(TL[it]);
	ull total = 0, cur = TL[it].first;
	pii cur_cust;

	it++;

	while (!wait.empty())
	{
		cur_cust = wait[0];
		pop_heap(wait.begin(), wait.end(), comp);
		wait.pop_back();

		//cout << cur_cust.first << " " << cur_cust.second << "\n";

		total += cur + cur_cust.second - cur_cust.first;

		cur += cur_cust.second;

		if (it >= N)
			continue;

		if (cur < TL[it].first)
		{
			wait.pb(TL[it]);
			push_heap(wait.begin(), wait.end(), comp);
			it++;
		}

		else
		{
			while (it < N && cur >= TL[it].first)
			{
				wait.pb(TL[it]);
				push_heap(wait.begin(), wait.end(), comp);
				it++;
			}
		}
	}

	cout << total / N << "\n";

	return 0;
}