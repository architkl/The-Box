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
typedef long long ll;

void calc(vector <int> &lps, vector <int> arr)
{
	lps[0] = 0;

	int i = 1, j = 0;
	while (i < arr.size())
	{
		if (arr[i] == arr[j])
			lps[i++] = ++j;
		
		else if (j == 0)
			lps[i++] = 0;

		else
			j = lps[j-1];
	}
}

int main()
{
	int n, w;
	cin >> n >> w;

	vector <int> a(n), b(w), diff_a(n-1), diff_b(w-1);
	for (int i = 0; i < n; i++)
		cin >> a[i];

	for (int i = 0; i < w; i++)
		cin >> b[i];

	for (int i = 1; i < n; i++)
		diff_a[i-1] = a[i-1] - a[i];

	for (int i = 1; i < w; i++)
		diff_b[i-1] = b[i-1] - b[i];

	vector <int> lps(diff_b.size());

	if (diff_b.size() == 0)
		cout << n << "\n";
	
	else
	{
		calc(lps, diff_b);

		int i = 0, j = 0, cnt = 0;
		while (i < diff_a.size())
		{
			if (diff_a[i] == diff_b[j])
			{
				i++;
				j++;
			}

			if (j == diff_b.size())
			{
				cnt++;
				j = lps[j-1];
			}

			else if (i < diff_a.size() && diff_a[i] != diff_b[j])
			{
				if (j != 0)
					j = lps[j-1];

				else
					i++;
			}
		}

		cout << cnt << "\n";
	}

	return 0;
}
