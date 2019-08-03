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

	int T;
	cin >> T;

	unordered_map <int, int> year = { {2010, 1}, {2015, 1}, {2016, 1}, {2017, 1}, {2019, 1} };

	int N;
	for (int i = 0; i < T; i++)
	{
		cin >> N;

		year[N] == 1 ? cout << "HOSTED\n" : cout << "NOT HOSTED\n";
	}

	return 0;
}