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

void rec(vector <int> arr, int pos, bool done[])
{
	if (pos == arr.size())
	{
		cout << "\n";
		return;
	}

	for (int i = 0; i < arr.size(); i++)
	{
		if (done[i])
			continue;

		cout << arr[i] << " ";

		done[i] = true;
		
		rec(arr, pos+1, done);

		done[i] = false;
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;

	if (n > 3)
	{
		int a = 2;
		while (a <= n)
		{
			cout << a << " ";
			a += 2;
		}

		a = 1;
		while (a <= n)
		{
			cout << a << " ";
			a += 2;
		}
	}

	else
		 cout << -1;

	cout << "\n";

	return 0;
}
/*
1 2 3 4
1 2 4 3
1 3 2 4
1 3 4 2
1 4 2 3
1 4 3 2
2 1 3 4
2 1 4 3
2 3 1 4
2 3 4 1
2 4 1 3
2 4 3 1
3 1 2 4
3 1 4 2
3 2 1 4
3 2 4 1
3 4 1 2
3 4 2 1
4 1 2 3
4 1 3 2
4 2 1 3
4 2 3 1
4 3 1 2
4 3 2 1*/