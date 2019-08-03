#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

int main()
{
	ifstream fi("test.txt");

	int n, m, k;
	fi >> n >> m >> k;
	//cin >> n >> m >> k;

	vector <int> i(k), j1(k), j2(k);
	long long int sum = 0;
	for (int l = 0; l < k; l++)
	{
		fi >> i[l] >> j1[l] >> j2[l];
		//cin >> i[l] >> j1[l] >> j2[l];

		sum += j2[l] - j1[l] + 1;
	}
	fi.close();

	long long int overlap = 0;

	for (int l = 0; l < k; l++)
	{
		if (j1[l] == 0)
			continue;

		for (int m = l+1; m < k; m++)
		{
			if (j1[m] == 0)
				continue;

			if (i[l] == i[m])
			{
				if ((j1[l] <= j1[m] && j1[m] <= j2[m]) && j2[m] <= j2[l])			//photo m is inside photo l
				{
					overlap += j2[m] - j1[m] + 1;
					j1[m] = 0;
					j2[m] = 0;
				}

				else if ((j1[l] <= j1[m] && j1[m] <= j2[l]) && j2[l] <= j2[m])		//photo m is after photo l and partially overlaps
				{
					overlap += j2[l] - j1[m] + 1;
					j2[l] = j1[m] - 1;
					j1[m] = j2[l] + 1;
				}

				else if ((j1[m] <= j1[l] && j1[l] <= j2[l]) && j2[l] <= j2[m])		//photo l is inside photo m
				{
					overlap += j2[l] - j1[l] + 1;
					j1[l] = 0;
					j2[l] = 0;
				}

				else if ((j1[m] <= j1[l] && j1[l] <= j2[m]) && j2[m] <= j2[l])		//photo l is after photo m and partially overlaps
				{
					overlap += j2[m] - j1[l] + 1;
					j2[m] = j1[l] - 1;
					j1[l] = j2[m] + 1;
				}

				//cout << l << " " << m << " " << overlap << "\n";
			}
		}
	}	

	cout << "\n" << (long long int)n*m << " " << sum << " " << overlap << "\n";

	cout << (long long int)n*m - (sum - overlap);

	return 0;
}