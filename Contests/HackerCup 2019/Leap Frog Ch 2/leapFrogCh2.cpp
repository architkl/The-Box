/*
Author: architkl
Language: C++ 14
*/

#include <iostream>
// #include <fstream>
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
	// ifstream fi("leapfrog_ch_.txt");

	int T, i = 0;
	cin >> T;

	string s;
	int c;
	while (T--)
	{
		cin >> s;

		i++;
		cout << "Case #" << i << ": ";

		c = count(s.begin(), s.end(), 'B');

		if (c == 1 && s.length() == 3)
			cout << "Y\n";

		else if (c >= 2 && c != s.length()-1)
			cout << "Y\n";

		else
			cout << "N\n";
	}

	// fi.close();

	return 0;
}