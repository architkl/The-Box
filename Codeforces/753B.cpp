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
	int cows, bulls, cur = 0;
	vector <int> nums;

	for (int i = 0; i <= 9; i++)
	{
		for (int j = 0; j < 4; j++)
			cout << i;
		cout << "\n";
		fflush(stdout);

		cin >> bulls >> cows;

		if (bulls)
			nums.pb(i);

		if (nums.size() == 4)
			break;
	}

	bool f = 0;
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			if (j == i)
				continue;

			for (int k = 0; k < 4; k++)
			{
				if (k == j || k == i)
					continue;

				for (int l = 0; l < 4; l++)
				{
					if (l == k || l == j || l == i)
						continue;

					cout << nums[i] << nums[j] << nums[k] << nums[l] << "\n";
					fflush(stdout);

					cin >> bulls >> cows;

					if (bulls == 4)
					{
						f = 1;
						break;
					}
				}

				if (f)
					break;
			}

			if (f)
				break;
		}

		if (f)
			break;
	}

	return 0;
}