#include <iostream>
#include <vector>
#include <stack>
#include <utility>
#include <climits>

using namespace std;

int main()
{
	int N, h;
	cin >> N >> h;

	vector <int> H(N+1), P(N+1);
	H[1] = h;
	for (int i = 2; i <= N; i++)
		cin >> H[i];
	for (int i = 2; i <= N; i++)
		cin >> P[i];

	vector <long long int> dp(N+1);
	stack < pair<int, long long int> > s;
	for (int i = N; i > 0; i--)
	{
		dp[i] = LLONG_MAX;
		long long int curr = LLONG_MAX;
		
		while (!s.empty() && H[s.top().first] <= H[i])
		{
			dp[i] = min(dp[i], s.top().second + H[i] - i);
			curr = min(curr, s.top().second);
			s.pop();
		}

		if (s.empty())
			dp[i] = min(dp[i], N - i + 1ll);

		else
			dp[i] = min(dp[i], dp[s.top().first] + s.top().first - i + H[s.top().first] - H[i] + P[s.top().first]);

		curr = min(curr, dp[i] + i - H[i] + P[i]);

		s.push(make_pair(i, curr));

		//cout << dp[i] << " ";
	}

	cout << dp[1] << "\n";

	return 0;
}
/*
5
5 2 2 6 2
0 2 -8 3 2

n = 5
e e e e 1
(5, 6)

n = 4
e e e 8 1
()

e e e 2 1
(4, 3)

n = 3
e e 10 2 1
(4, 3) (3, 3)

n = 2
e 3 10 2 1
(4, 3)

e 3 10 2 1
(4, 3) (2, 3)

n = 1
7 7 10 2 1
(4, 3)

7 3 10 2 1
*/