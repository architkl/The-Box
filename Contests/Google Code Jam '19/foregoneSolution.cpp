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

	int t, case_ = 0;
	cin >> t;

	string n;
	while (t--)
	{
		case_++;

		cin >> n;

		string a, b;
		int start = 0;
		while (n[start] != '4')
		{
			a += n[start];
			start++;
		}

		for (int i = start; i < n.length(); i++)
		{
			if (n[i] == '4')
			{
				a += "3";
				b += "1";
			}

			else
			{
				a += n[i];
				b += "0";
			}
		}

		cout << "Case #" << case_ << ": " << a << " " << b << "\n";
	}

	return 0;
}