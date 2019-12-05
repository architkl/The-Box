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
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;

	string s = "";
	int temp = n;
	while (temp/10)
	{
		s += to_string((temp%10) / 5);
		temp /= 10;
	}

	reverse(s.begin(), s.end());

	bitset <32> mybs(s);

	if (n == 4 || n == 7)
		cout << n / 3 << "\n";

	else
		cout << (temp/5)*(int)(pow(2, s.length())) + 2*((int)(pow(2, (s.length()))) - 1) + mybs.to_ulong() + 1 << "\n";

	return 0;
}