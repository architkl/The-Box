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

	vector <int> a(n);
	unordered_map <int, bool> ex;
	int req = n;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];

		ex[a[i]] = 1;

		while (ex[req])
		{
			cout << req << " ";
			req--;
		}

		cout << "\n";
	}

	return 0;
}