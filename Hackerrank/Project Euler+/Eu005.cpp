#include <iostream>
#include <vector>

using namespace std;

const int prime[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37};

int main()
{
	int T;
	cin >> T;

	vector <int> N;
	int t;
	for (int i = 0; i < T; i++)
	{
		cin >> t;
		N.push_back(t);
	}

	int ans[T];
	for (int i = 0; i < T; i++)
		 ans[i] = 1;

	for (int i = 0; i < T; i++)
	{
		int arr[N[i] + 1], f;
		for (int j = 2; j <= N[i]; j++)
			arr[j] = j;

		for (int j = 0; j < 12; j++)
		{
			f = 0;
			
			for (int k = 2; k <= N[i]; k++)
			{
				if (arr[k] % prime[j] == 0)
				{
					arr[k] /= prime[j];
					f = 1;
				}
			}

			if (f)
			{
				ans[i] *= prime[j];
				j--;
			}
		}
	}

	for (int i = 0; i < T; i++)
		cout << ans[i] << "\n";

	return 0;
}