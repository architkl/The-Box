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

int N, x;

void printPattern(int n)
{
	if (n == N)
		return;

	cout << n << " ";

	x *= ((n > 0) ? 1 : -1);

	printPattern(n + x);
}

int main()
{
	int T;
	cin >> T;

	while (T--)
	{
		cin >> N;

		x = -5;

		cout << N << " ";
		printPattern(N-5);
		cout << N << "\n";
	}

	return 0;
}