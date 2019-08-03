#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int n_MAX = 100, m_MAX = 100;

int wall[n_MAX][m_MAX];
vector <int> v;

void iter(int n, int m, int bound)
{
	int i = bound, j = bound;
	for (; j < m-bound; j++)
	//{
		v.push_back(wall[i][j]);
		//cout << wall[i][j] << " ";}
	i = bound + 1;
	j = m - bound - 1;
	for (; i < n-bound; i++)
	//{
		v.push_back(wall[i][j]);
		//cout << wall[i][j] << " ";}

	i = n - bound - 1;
	j = m - bound - 2;
	for (; j >= bound; j--)
	//{
		v.push_back(wall[i][j]);
		//cout << wall[i][j] << " ";}

	i = n - bound - 2;
	j = bound;
	for (; i > bound; i--)
	//{
		v.push_back(wall[i][j]);
		//cout << wall[i][j] << " ";}
}

/*
$ $ $
$ $ $
$ $ $
*/

int main()
{
	int n, m;
	cin >> n >> m;

	v.resize(n*m);

	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> v[i*m + j];

	sort(v.begin(), v.end());

	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			wall[i][j] = v[i*m + j];
		
	v.clear();
	int bound = min(n, m), flag = 0;
	if (bound % 2)
		flag = 1;
	bound /= 2;
	
	for (int i = 0; i < bound; i++)
		iter(n, m, i);

	if (flag)
	{
		if (n < m)
		{
			//cout << "n\n";
			for (int i = n/2; i < m - n/2; i++)
				v.push_back(wall[n/2][i]);
		}
		else
		{
			//cout << "m\n";
			for (int i = m/2; i < n - m/2; i++)
				v.push_back(wall[i][m/2]);	
		}
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cout << v[i*m + j] << " ";
		}
		cout << "\n";
	}
	
	return 0;
}