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

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;

	string names[5] = { "Sheldon", "Leonard", "Penny", "Rajesh", "Howard" };

	int range = 5, temp = 5;
	while (temp < n)
	{
		range *= 2;
		temp += range;
	}

	cout << names[int(ceil((double)(n - temp + range) / (range / 5)))-1] << "\n";

	return 0;
}