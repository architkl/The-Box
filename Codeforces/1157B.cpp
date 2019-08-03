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

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;

	string s;
	cin >> s;

	int arr[10];
	for (int i = 1; i < 10; i++)
		cin >> arr[i];

	int l = 1, r = 0;
	for (int i = 0; i < n; i++)
	{
		if (s[i] < (arr[s[i]-48] + 48))
		{
			l = i;
			while (i < n && s[i] <= (arr[s[i]-48] + 48))
				i++;

			r = i-1;
			break;
		}
	}

	for (int i = l; i <= r; i++)
		s[i] = char(arr[s[i]-48]+48);

	for (int i = 0; i < n; i++)
		cout << s[i];

	cout << "\n";

	return 0;
}