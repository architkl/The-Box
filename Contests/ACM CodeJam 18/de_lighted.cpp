#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int n;
	cin >> n;

	vector <int> a(n), b(n);
	for (int i = 0; i < n; i++)
		cin >> a[i] >> b[i];
	
	int m = 999999, temp;
	for (int i = 1; i < n; i++)
	{
		temp = 0;
		for (int j = n-1; j > 0; j--)
		{
			if (a[j] - b[j] <= a[j-1])
			{
				int k = j-1;
				while (a[j] - b[j] <= a[k])
				{
					temp++;
					k--;
				}

				j = k + 1;
			}
		}

		if (temp < m)
			m = temp;
	}

	return 0;
}