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
typedef unsigned long long ull;
typedef long long ll;

int main()
{
	int Q;
	cin >> Q;

	string str;
	while (Q--)
	{
		cin >> str;

		stack <char> S;
		bool f = 1;
		for (int i = 0; i < str.length(); i++)
		{
			if (str[i] <= 'M')
				S.push(str[i]);

			else
			{
				if (S.empty() || str[i]-'A' != 'Z'-S.top())
				{
					f = 0;
					break;
				}

				S.pop();
			}
		}

		(f && S.empty()) ? cout << "Valid\n" : cout << "Invalid\n";
	}

	return 0;
}