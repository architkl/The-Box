#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int t;
	cin >> t;

	int n;
	for (int i = 0; i < t; i++)
	{
		cin >> n;

		vector <int> a(n);
		for (int j = 0; j < n; j++)
			cin >> a[j];

		int cnt = 0;
		for (int j = 1; j < n; j++)
		{
			if (a[j] < a[j-1])
			{
				cnt++;

				if (a[j] < a[j-2] && j > 1)
					cnt = 2;
			}
			
			if (cnt == 2)
				break;
		}

		if (cnt <= 1)
			cout << "YES\n";

		else
			cout << "NO\n";
	}

	return 0;
}