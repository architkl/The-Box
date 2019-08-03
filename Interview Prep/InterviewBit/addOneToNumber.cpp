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

	vector <int> A(n);
	for (int i = 0; i < n; i++)
		cin >> A[i];

	reverse(A.begin(), A.end());

	int carry = 1;
	for (int i = 0; i < A.size(); i++)
	{
		A[i] += carry;
		carry = A[i] / 10;
		A[i] %= 10;

		if (!carry)
			break;
	}

	if (carry)
		A.push_back(1);

	else
	{
		while (A.back() == 0)
			A.pop_back();
	}

	reverse(A.begin(), A.end());

	for (auto i : A)
		cout << i << " ";
	cout << "\n";

	return 0;
}