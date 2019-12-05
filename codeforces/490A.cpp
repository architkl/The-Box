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

const int N_MAX = 5005;

int arr[N_MAX];

int min_(int a, int b)
{
	return (a < b) ? a : b;
}

int main()
{
	int n;
	cin >> n;

	int c1[n] = {}, c2[n] = {}, c3[n] = {}, i1 = 0, i2 = 0, i3 = 0;

	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];

		if (arr[i] == 1)
		{
			c1[i1] = i+1;
			i1++;
		}

		else if (arr[i] == 2)
		{
			c2[i2] = i+1;
			i2++;
		}

		else
		{
			c3[i3] = i+1;
			i3++;
		}
	}

	int w = min_(i1, min_(i2, i3));
	cout << w << "\n";

	for (int i = 0, j = 0, k = 0; i < i1 && j < i2 && k < i3; i++, j++, k++)
		cout << c1[i] << " " << c2[j] << " " << c3[k] << "\n";

	return 0;
}