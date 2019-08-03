/*
Author: architkl
Language: C++ 11
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

int mod_ex(int a, int b, int m)
{
	if (b == 1)
		return a % m;

	long long int res = mod_ex(a, b/2, m);
	res *= res;
	res %= m;

	if (b % 2)
	{
		res *= a;
		res %= m;
	}

	return res;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int N, Q, K;
	cin >> N >> Q >> K;

	vector <int> A(N);
	for (int i = 0; i < N; i++)
		cin >> A[i];

	string str;
	cin >> str;

	

	return 0;
}