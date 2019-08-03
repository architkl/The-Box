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

int comp(vector <int> arr, int s)
{
	int res = 0;

	for (int i = 0; i < arr.size(); i++)
	{
		res += ceil((float)arr[i] / s);
		// cout << ceil(arr[i] / s) << "\n";
	}
	
	return res;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;

	vector <int> arr(n);
	for (int i = 0; i < n; i++)
		cin >> arr[i];

	int H;
	cin >> H;

	int l = 1, h = 1000000, mid;
	while (l <= h)
	{
		mid = (l + h) / 2;

		// cout << mid << "\n";

		if (comp(arr, mid) <= H)
			h = mid-1;

		else
			l = mid+1;
	}

	// cout << h << " " << l << "\n";
	// cout << comp(arr, 3) << "\n";

	while (comp(arr, h) > H)
		h++;

	cout << h << "\n";

	return 0;
}