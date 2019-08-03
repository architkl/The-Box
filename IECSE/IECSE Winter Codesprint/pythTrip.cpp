#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int check(long long int a, long long int b, long long int c)
{
	return c*c == a*a + b*b ? 1 : 0;
}

int main()
{
	int T;
	cin >> T;

	int n;
	for (int i = 0; i < T; i++)
	{
		cin >> n;

		vector <long long int> set(n);
		for (int j = 0; j < n; j++)
			cin >> set[j];

		sort(set.begin(), set.end());

		int flag = 0;
		for (int j = 0; j < n-2; j++)
		{
			for (int k = j+1; k < n-1; k++)
			{
				for (int l = k+1; l < n; l++)
				{
					if (check(set[j], set[k], set[l]))
					{
						flag = 1;
						break;
					}
				}
				if (flag)
					break;
			}
			if (flag)
				break;
		}

		if (flag)
			cout << "YES\n";
		else
			cout << "NO\n";
	}

	return 0;
}