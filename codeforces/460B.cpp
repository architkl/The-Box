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

long long int arr[85];

void pre(int a, int b, int c)
{
	for (int i = 1; i < 82; i++)
		arr[i] = (b * (long long)(pow(i, a)) + c);
}

int sod(int x)
{
	int sum = 0;
	while (x != 0)
	{
		sum += x % 10;
		x /= 10;
	}

	return sum;
}

// int eval(int a, int b, int c, long long int x)
// {
// 	return (b * (long long)(pow(sod(x), a)) + c);
// }

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int a, b, c;
	cin >> a >> b >> c;

	pre(a, b, c);

	vector <int> sol;
	for (int i = 1; i < 82; i++)
	{
		if (arr[i] > 0 && arr[i] < 1e9 && sod(arr[i]) == i)
			sol.pb(arr[i]);
	}

	cout << sol.size() << "\n";
	for (auto i : sol)
		cout << i << " ";

	cout << "\n";

	return 0;
}