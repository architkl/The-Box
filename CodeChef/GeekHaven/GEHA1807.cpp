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

	int N, X;
	char l;
	string str;
	for (int i = 0; i < T; i++)
	{
		cin >> N >> X >> l;

		cin.ignore();

		int cnt = 0;

		for (int j = 0; j < N; j++)
		{
			getline(cin, str);

			if (str.find(l) != -1 && j >= X)
				cnt++;
		}

		cout << cnt << "\n";
	}

	return 0;
}