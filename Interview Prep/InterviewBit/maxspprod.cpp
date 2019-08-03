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

	vector <int> left_sp(n, 0), right_sp(n, 0);
	stack < pair <int, int> > S;
	S.push(make_pair(A[0], 0));
	for (int i = 1; i < n; i++)
	{
		while (!S.empty() && A[i] > S.top().first)
		{
			right_sp[S.top().second] = i;
			S.pop();
		}

		S.push(make_pair(A[i], i));
	}

	while (!S.empty())
		S.pop();

	S.push(make_pair(A[A.size()-1], A.size()-1));
	for (int i = A.size()-2; i >= 0; i--)
	{
		while (!S.empty() && A[i] > S.top().first)
		{
			left_sp[S.top().second] = i;
			S.pop();
		}

		S.push(make_pair(A[i], i));
	}

	long long int ans = 0;
	for (int i = 0; i < A.size(); i++)
		ans = max(ans, (long long)left_sp[i] * right_sp[i]);
	
	cout << ans << "\n";

	return 0;
}