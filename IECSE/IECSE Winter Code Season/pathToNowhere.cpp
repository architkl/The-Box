#include <iostream>
#include <math.h>

using namespace std;

const int K = pow(10, 9) + 7;
const int v = 4;				//vertices
long long int mat[v][v] = { {0, 1, 1, 1},
				  {1, 0, 1, 1},
				  {1, 1, 0, 1},
				  {1, 1, 1, 0} };

void multMat(long long int mat1[v][v], long long int mat2[v][v], long long int res[v][v])
{
	for (int i = 0; i < v; i++)
	{
		for (int j = 0; j < v; j++)
		{
			res[i][j] = 0;
			for (int k = 0; k < v; k++)
			{
				res[i][j] += mat1[i][k] * mat2[k][j];
				res[i][j] %= K;
			}
		}
	}
}

void modularExp(long long int a[v][v], long long int res[v][v], long long int n)
{
	if (n == 1)
		return;

	long long int temp1[v][v], temp2[v][v];
	for (int i = 0; i < v; i++)
		for (int j = 0; j < v; j++)
			temp1[i][j] = a[i][j];

	modularExp(a, temp1, n/2);
	multMat(temp1, temp1, temp2);

	for (int i = 0; i < v; i++)
		for (int j = 0; j < v; j++)
			res[i][j] = temp2[i][j];

	if (n % 2)
		multMat(temp2, mat, res);
}

int main()
{
	long long int n;
	cin >> n;

	long long int ans[v][v];

	modularExp(mat, ans, n);
	cout << ans[0][0] << "\n";

	return 0;
}