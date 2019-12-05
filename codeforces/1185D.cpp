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

bool check(vector <int> a)
{
	int d = a[1] - a[0];
	for (int i = 1; i < a.size(); i++)
		if (a[i] != a[i-1]+d)
			return false;
	
	return true;
}

int main()
{
	// ios_base::sync_with_stdio(false);
	// cin.tie(NULL);

	int n;
	cin >> n;

	vector <int> b(n);
	unordered_map <int, int> mymap;
	for (int i = 0; i < n; i++)
	{
		cin >> b[i];
		mymap[b[i]] = i+1;
	}

	sort(b.begin(), b.end());

	if (check(vector <int> (b)) || check(vector <int> (b.begin()+1, b.end())))
		cout << mymap[b[0]] << "\n";

	else if (check(vector <int> (b.begin(), b.end()-1)))
		cout << mymap[b[n-1]] << "\n";

	else
	{
		if ((b.back()-b.front()) % (n-2))
			cout << "-1\n";

		else
		{
			int am = (b.back() - b.front()) / (n - 2), term = b.front(), idx = -1;
			for (int i = 0; i < n; i++)
			{
				if (term != b[i] && idx == -1)
				{
					idx = mymap[b[i]];
					continue;
				}

				else if (term != b[i])
				{
					idx = n+1;
					break;
				}

				term += am;
			}

			if (idx == n+1)
				cout << "-1\n";

			else
				cout << idx << "\n";
		}
	}

	return 0;
}