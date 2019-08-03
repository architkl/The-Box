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

	int T;
	cin >> T;

	int n, a, b;
	while (T--)
	{
		cin >> n >> a >> b;

		vector <int> A(n);
		for (int i = 0; i < n; i++)
			cin >> A[i];

		int cnt_a = 0, cnt_b = 0, cnt_ab = 0;
		for (auto i : A)
		{
			if ((i % a == 0) && (i % b == 0))
			{
				cnt_ab++;
				continue;
			}

			if (i % a == 0)
				cnt_a++;

			else if (i % b == 0)
				cnt_b++;
		}

		if (cnt_a + !(!cnt_ab) > cnt_b)
			cout << "BOB\n";

		else
			cout << "ALICE\n";
	}

	return 0;
}