#include <iostream>
#include <math.h>

using namespace std;

int main()
{
	int T;
	cin >> T;

	long long int m, n;
	long long int expo, ans, mn, mx;
	for (int i = 0; i < T; i++)
	{
		cin >> n >> m;

		long long int no = pow(2, int(log2(m)));
		long long int pos = m - no + 1;
		long long int spaces = n - no + 1;
		long long int extra = spaces - no * (spaces / no);
		long long int range;

		//cout << no << "\n" << pos << "\n" << spaces << "\n" << extra << "\n";

		if (pos <= extra)
			range = ceil(double(spaces) / no);
		
		else
			range = spaces / no;

		//cout << range << "\n";

		if (range % 2)
			cout << range / 2 << " " << range / 2 << "\n";

		else
		{
			//cout << range << "\n";
			range--;
			cout << max(range / 2, range - range / 2) << " "
				 << min(range / 2, range - range / 2) << "\n";
		}
	}

	return 0;
}