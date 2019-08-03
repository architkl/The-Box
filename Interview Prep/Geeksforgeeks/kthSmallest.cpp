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

void swap(int &a, int &b)
{
	int c = a;
	a = b;
	b = c;
}

int partition(vector <int> &A, int l, int h)
{
	int p = A[h], i = l;
	for (int j = l; j < h; j++)
	{
		if (A[j] < p)
		{
			swap(A[i], A[j]);
			i++;
		}
	}

	swap(A[i], A[h]);
	return i;
}

int quicksort(vector <int> &v, int l, int h, int k)
{
	int pos = partition(v, l, h);

	if (pos == k-1)
		return v[pos];

	if (pos > k-1)
		return quicksort(v, l, pos-1, k);

	else
		return quicksort(v, pos+1, h, k);
}

int main()
{
	int T;
	cin >> T;

	int N, K;
	while (T--)
	{
		cin >> N;

		vector <int> a(N);
		for (int i = 0; i < N; i++)
			cin >> a[i];

		cin >> K;

		cout << quicksort(a, 0, N-1, K) << "\n";
	}

	return 0;
}