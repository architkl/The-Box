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

void subsum(vector <int> seq, vector <int>& store)
{
	store[0] = 0;
	
	int n = pow(2, seq.size());

	for (int i = 1; i < n; i++)
	{
		int x = i, pos = 0, sum = 0;
		while (x)
		{
			if (x & 1)
				sum += seq[pos];
			
			pos++;
			x /= 2;
		}

		store[i] = sum;
		// cout << sum << " ";
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, a, b;
	cin >> n >> a >> b;

	vector <int> s(n);
	for (int i = 0; i < n; i++)
		cin >> s[i];

	int f_half = n/2;
	int s_half = n - f_half;

	vector <int> X((int)pow(2, f_half)), Y((int)pow(2, s_half));

	subsum(vector <int> (s.begin(), s.begin()+f_half), X);
	subsum(vector <int> (s.begin()+f_half, s.end()), Y);

	/*for (auto i : X)
		cout << i << " ";

	cout << "\n";

	for (auto i : Y)
		cout << i << " ";*/

	// sort(X.begin(), X.end());
	sort(Y.begin(), Y.end());

	long long int ans = 0, temp;
	int l, r, mid;
	for (int i = 0; i < X.size(); i++)
	{
		l = 0;
		r = Y.size()-1;
		
		while (l <= r)
		{
			mid = (l+r) / 2;
			temp = X[i] + Y[mid];

			if (temp < a)
				l = mid+1;

			else
				r = mid-1;
		}

		int n1 = Y.size() - l + 1;

		l = 0;
		r = Y.size()-1;
		
		while (l <= r)
		{
			mid = (l+r) / 2;
			temp = X[i] + Y[mid];

			if (temp <= b)
				l = mid+1;

			else
				r = mid-1;
		}

		int n2 = Y.size() - l + 1;

		ans += n1 - n2;
	}

	cout << ans << "\n";

	return 0;
}