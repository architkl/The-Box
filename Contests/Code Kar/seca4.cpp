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

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int req[10] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};

	int led;
	string str;
	cin >> str >> led;

	int count = 0;

	for (int i = 0; i < str.length(); i++)
		count += req[str[i] - 48];

	(led >= count) ? cout << "YES\n" : cout << "NO\n";

	return 0;
}