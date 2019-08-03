#include <iostream>
#include <vector>

using namespace std;

int find_max(vector <int> v, int i, int j)
{
	int max = i;
	for (int k = i+1; k < j; k++)
	{
		if (v[k] > v[max])
			max = k;
	}

	return max;
}

int main()
{
	int T;
	cin >> T;

	int N;
	for (int i = 0; i < T; i++)
	{
		cin >> N;

		vector <int> stock(N);
		for (int j = 0; j < N; j++)
			cin >> stock[j];

		int profit = 0, temp = 0, g_max = find_max(stock, 0, N);
		for (int j = 0; j < N; j++)
		{
			while (j < g_max)
			{
				profit += stock[g_max] - stock[j];
				j++;
			}

			g_max = find_max(stock, j+1, N);
		}

		cout << profit << "\n";
	}

	return 0;
}
/*
2 4 2 1 3
*/