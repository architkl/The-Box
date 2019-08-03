/*
Author: architkl
Language: C++ 11
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <math.h>

using namespace std;

#define push_back pb
#define make_pair mp

typedef pair <int, int> pii;
typedef unsigned long long ull;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int T;
	cin >> T;

	int P1, P2, K;
	for (int i = 0; i < T; i++)
	{
		cin >> P1 >> P2 >> K;

		((P1 + P2) / K) % 2 ? cout << "COOK\n" : cout << "CHEF\n";
	}	

	return 0;
}