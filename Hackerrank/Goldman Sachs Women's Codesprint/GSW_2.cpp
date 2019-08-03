/*
Author: architkl
Language: C++ 11
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

int calculate(vector <int> v, int n)
{
	int res = v[1];
	for (int i = 2; i <= n; i++)
		res += abs(v[i] - v[i-1]);

	return res;
}

void swap(vector <int> &v, int i, int j)
{
	int c = v[i];
	v[i] = v[j];
	v[j] = c;
}

int main()
{
	int N;
	cin >> N;

	vector <int> p(N+5);
	for (int i = 1; i <= N; i++)
		cin >> p[i];

	//vector <int> v(p);
	int sum = calculate(p, N), mn, temp, before, after;
	// cout << sum << "\n";
	mn = sum;
	for (int i = 1; i < N; i++)
	{
		for (int j = i+1; j <= N; j++)
		{
			//swap(v, i, j);
			before = (abs(p[i]-p[i-1]) + abs(p[i+1]-p[i]) + abs(p[j]-p[j-1]) + abs(p[j+1]-p[j]));
			after = (abs(p[j]-p[i-1]) + abs(p[i+1]-p[j]) + abs(p[i]-p[j-1]) + abs(p[j+1]-p[i]));

			if (j == i+1)
			{
				before = abs(p[i] - p[i-1]) + abs(p[j]-p[i]) + abs(p[j+1] - p[j]);
				after = abs(p[j] - p[i-1]) + abs(p[i]-p[j]) + abs(p[j+1] - p[i]);
			}

			if (j == N)
			{
				before -= p[j];
				after -= p[i];
			}

			temp = sum - before + after;

			//cout << i << " " << j << "  " << before << " " << after << "  " << sum << " " << temp << "\n";

			if (temp < mn)
				mn = temp;
		}
	}

	cout << mn << "\n";

	return 0;
}