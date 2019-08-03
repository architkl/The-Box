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

unordered_map <char, int> val({{'I', 1}, {'V', 5}, {'X', 10}, {'L', 50}, {'C', 100}, {'D', 500}, {'M', 1000}});

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int T;
	cin >> T;

	string s, ans;
	int res;
	while (T--)
	{
		cin >> s;

		res = 0;
		ans = "";

		for (auto i : s)
			res += val[i];

		while (res >= 1000)
		{
			ans += "M";
			res -= 1000;
		}

		if (res >= 900)
		{
			ans += "CM";
			res -= 900;
		}

		if (res >= 500)
		{
			ans += "D";
			res -= 500;
		}

		if (res >= 400)
		{
			ans += "CD";
			res -= 400;
		}

		while (res >= 100)
		{
			ans += "C";
			res -= 100;
		}

		if (res >= 90)
		{
			ans += "XC";
			res -= 90;
		}

		if (res >= 50)
		{
			ans += "L";
			res -= 50;
		}

		if (res >= 40)
		{
			ans += "XL";
			res -= 40;
		}

		while (res >= 10)
		{
			ans += "X";
			res -= 10;
		}

		if (res == 9)
		{
			ans += "IX";
			res -= 9;
		}

		if (res >= 5)
		{
			ans += "V";
			res -= 5;
		}

		if (res == 4)
		{
			ans += "IV";
			res -= 4;
		}

		while (res >= 1)
		{
			ans += "I";
			res--;
		}

		cout << ans << "\n";
	}

	return 0;
}