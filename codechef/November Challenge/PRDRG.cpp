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

	int N;
	while (T--)
	{
		cin >> N;

		int num = 1, den = 2;

		for (int i = 0; i < N-1; i++)
		{
			num = den-num;
			den *= 2;
		}

		cout << num << " " << den << " ";
	}

	return 0;
}