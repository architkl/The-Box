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
	int n;
	cin >> n;

	string s;
	cin >> s;

	int cnt_0 = 0, cnt_1 = 0;
	for (auto i : s)
	{
		if (i == '1')
			cnt_1++;
		else
			cnt_0++;
	}

	if (cnt_0 != cnt_1)
		cout << "1\n" << s << "\n";
	
	else
	{
		cout << "2\n" << s[0] << " ";
		for (int i = 1; i < s.length(); i++)
			cout << s[i];
		cout << "\n";
	}

	return 0;
}