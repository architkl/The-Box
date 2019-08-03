#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	int n;
	cin >> n;

	vector <int> P(n);
	for (int i = 0; i < n; i++)
		cin >> P[i];

	int max_profit = -999999;
	for (int i = 0; i < n; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			if (p[j] <= p[i])
				continue;

			for (int k = j + 1; k < n; k++)
			{
				if (p[k] <= p[j])
					continue;

				max_profit = max(max_profit, p[i] + p[j] + p[k]);
			}
		}
	}

	if (max_profit = -999999)
		cout << -1 << "\n";

	else
		cout << max_profit << "\n";

	return 0;
}