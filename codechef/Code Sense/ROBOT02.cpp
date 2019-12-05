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

int dist(string str, int jmp, int N)
{
	for (int i = jmp; i < str.length(); i++)
	{
		if (N == 0)
			break;

		if (str[i] == 'X')
		{
			str[i] = 'O';
			N--;
		}
	}

	int ans = 0, temp = 0, x = 1;
	for (int i = 0; i < str.length(); i++)
	{
		if (str[i] == 'O')
			temp += x;

		else
			x *= -1;

		ans = max(ans, abs(temp));
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	string str;
	cin >> str;

	int N;
	cin >> N;

	int dist = 0;
	for (int i = 0; i < str.length(); i++)
	{

	}

	return 0;
}