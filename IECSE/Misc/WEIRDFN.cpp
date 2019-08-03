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

const int K = pow(10, 9) + 7;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int t;
	cin >> t;

	long long int a, b, c, n;
	while (t--)
	{
		cin >> a >> b >> c >> n;
		
		vector <int> F(n+1);
		F[1] = 1;

		priority_queue <int, vector <int>, greater <int>> mn;
		priority_queue <int> mx;

		mx.push(F[1]);

		int med, temp;

		for (int i = 2; i <= n; i++)
		{
			med = mx.top();

			F[i] = (a*med + b*i + c) % K;

			if (mx.size() > mn.size())
			{
				if (F[i] < mx.top())
				{
					temp = mx.top();
					mx.pop();

					mn.push(temp);
					mx.push(F[i]);
				}

				else
					mn.push(F[i]);
			}

			else
			{
				if (F[i] <= mn.top())
					mx.push(F[i]);

				else
				{
					temp = mn.top();
					mn.pop();

					mx.push(temp);
					mn.push(F[i]);
				}
			}
		}

		long long int sum = 0;
		for (auto i : F)
			sum += i;

		cout << sum << "\n";
	}

	return 0;
}