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

	int n;
	cin >> n;

	string s;
	cin >> s;

	int cnt = 0;
	for (int i = 0; i < n; i++)
		if (s[i] == '8')
			cnt++;

	if (cnt == 0)
		cout << "NO\n";

	else
	{
		int p_turns = (n-11) / 2;
		int v_turns = n - 11 - p_turns;

		if (p_turns >= cnt)
			cout << "NO\n";

		else
		{
			int pos = 0, temp = p_turns;
			for (; pos < n; pos++)
			{
				if (s[pos] == '8')
					temp--;
				
				if (temp == -1)
					break;
			}

			if (pos - p_turns <= v_turns)
				cout << "YES\n";

			else
				cout << "NO\n";
		}
	}

	return 0;
}