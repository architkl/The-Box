/*
Author: architkl
Language: C++
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <string>
#include <math.h>

using namespace std;

#define push_back pb

typedef pair <int, int> pii;

bool mycomp(int a, int b)
{
	return a > b;
}

int main()
{
	int N;
	cin >> N;

	int arr[N][2];
	map <int, int> mymap;
	for (int i = 0; i < N; i++)
		cin >> arr[i][0];

	for (int i = 0; i < N; i++)
	{
		cin >> arr[i][1];

		mymap[arr[i][0]] = arr[i][1];
	}

	bool (*fn_pt)(int, int) = mycomp;

	set < int, bool (*)(int, int) > A(fn_pt);
	for (int i = 0; i < N; i++)
		A.insert(arr[i][0]);

	int k;
	cin >> k;

	int q;
	for (int i = 0; i < k; i++)
	{
		cin >> q;

		cout << mymap[*(A.lower_bound(q))] << "\n";
	}

	return 0;
}