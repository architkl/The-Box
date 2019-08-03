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

	long long int n, k;
	cin >> n >> k;

	long long int sum = k * (k + 1) / 2, count = 1;
	if (sum > n)
		cout << "NO\n";
	
	else
	{
		int count = (n - sum) / k;
		sum += count*k;

		vector <long long int> arr(k);
		arr[0] = count+1;
		for (int i = 1; i < k; i++)
		{
			arr[i] = arr[i-1] + 1;
			// cout << arr[i] << " ";
		}

		int ptr = k-1, f = 1, x;

		while (ptr > 0)
		{
			x = min(2*arr[ptr-1] - arr[ptr], n-sum);
			arr[ptr] += x;
			sum += x;

			// cout << arr[ptr] << " ";
			ptr--;

			// if (ptr < 0)
			// 	break;
		}

		if (sum != n)
			cout << "NO\n";

		else
		{
			int sum = 0;
			cout << "YES\n";
			for (int i = 0; i < k; i++)
			{
				cout << arr[i] << " ";
			}
			cout << "\n";
		}
	}

	return 0;
}