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

const int sieve_max = 1e7;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int t;
	cin >> t;

	string str;

	while (t--)
	{
		cin >> str;

		int count = 0;
		for (int i = 0; i < str.length()-1; i++)
		{
			if (str[i] == 'p' && str[i+1] == 'q')
			{
				int j = i+1, f = 1;
				while (j < str.length() && str[j] != 'p')
				{
					if (str[j] != 'q')
					{
						f = 0;
						break;
					}
					j++;
				}

				if (j == str.length())
					break;

				if (f)
					count++;
			}
		}

		cout << count << "\n";
	}

	return 0;
}