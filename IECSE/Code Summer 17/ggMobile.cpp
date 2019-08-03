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

	while (1)
	{
		cin >> n;

		if (n == 0)
			break;

		vector <int> a(n);
		stack <int> S;
		unordered_map <int, bool> in_stack;

		for (int i = 0; i < n; i++)
			cin >> a[i];
		
		int req = 1;
		bool f = 1;
		for (int i = 0; i < n; i++)
		{
			S.push(a[i]);
			in_stack[a[i]] = 1;

			while (!S.empty() && req == S.top())
			{
				S.pop();
				in_stack[req] = 0;
				req++;
			}

			if (in_stack[req])
			{
				f = 0;
				break;
			}
		}

		f ? cout << "yes\n" : cout << "no\n";
	}

	return 0;
}