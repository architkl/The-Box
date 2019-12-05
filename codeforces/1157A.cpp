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

int f(int x)
{
	x += 1;
	while (x % 10 == 0)
		x /= 10;

	return x;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;

	int cnt = 1, temp = n;
	unordered_map <int, bool> freq;
	freq[n] = 1;
	while (1)
	{
		temp = f(temp);
		if (freq[temp])
			break;

		cnt++;

		freq[temp] = 1;
	}

	cout << cnt << "\n";

	return 0;
}