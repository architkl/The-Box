#include <fstream>
#include <math.h>
#include <iomanip>

using namespace std;

#define sq(a) pow(a, 2)

const int sz = 3;

long long int max_custom(int a[sz][sz])
{
	int mx = 0, temp;

	for (int i = 0; i < sz; i++)
	{
		for (int j = 0; j < sz; j++)
		{
			if (i == j)
				continue;

			for (int k = 0; k < sz; k++)
			{
				if (k == i || k == j)
					continue;

				temp = sq(a[0][i]) + sq(a[1][j]) + sq(a[2][k]);

				if (mx < temp)
					mx = temp;
			}
		}
	}

	return mx;
}

int main()
{
	ifstream fi("input.txt");
	ofstream fo("output.txt");

	int table[sz][sz];

	for (int i = 0; i < sz; i++)
		for (int j = 0; j < sz; j++)
			fi >> table[i][j];

	fi.close();

	long long int mx = max_custom(table);

	fo << setprecision(6) << fixed << sqrt(mx);

	fo.close();

	return 0;
}