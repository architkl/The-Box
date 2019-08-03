#include <iostream>
#include <vector>

using namespace std;

int MIN_INT = -999999999;

/*
int cut_vertical(vector < vector <int> > A, int x, int y, int K)
{
	int n = v.size(), m = v[0].size();
	
	//vertical strip
	for (int i = x; i-x < K; i++)
		A[i][y] = 0;

	int sum = MIN_INT, temp = 0;
	for (int i = 0; i < n; i++)
	{
		if (x < i)
			break;

		for (int j = 0; j < m; j++)
		{
			if (j > y)
				break;

			for (int jy = m-1; jy >= j; jy--)
			{
				if (jy < y)
					break;

				for (int ix = n-1; ix >= i; ix--)
				{
					if (ix < x + K)
						break;

					for (int ky = j < ky <= jy; ky++)
					{
						for (int kx = i; kx <= ix; kx++)
						{
							temp += A[kx][ky];
						}
					}
				}
			}
		}
	}
}
*/

int find_min(vector < vector <int> > A)
{
	int n = A.size(), m = A[0].size();
	int min = A[0][0];
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (A[i][j] < min)
				min = A[i]][j];
		}
	}

	return min;
}

int main()
{
	int n, m, k;
	cin >> n >> m >> k;

	vector <int> neg_x, neg_y;
	vector < vector <int> > A(n, vector <int>(m));
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> A[i][j];

			if (A[i][j] < 0)
			{
				neg_x.push_back(i);
				neg_y.push_back(j);
			}
		}
	}

	int sum = 0;
	if (neg_x.size() == 0 || neg_x.size() == 1)
	{
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
				sum += A[i][j];

		if (neg_x.size() == 1)
			sum -= A[neg_x[0]][neg_y[0]];

		else
			sum -= find_min(A);
	}

	cout << sum;

	return 0;
}