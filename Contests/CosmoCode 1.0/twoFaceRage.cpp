#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int mark[105] = {};

int main()
{
	int n, k;
	cin >> n >> k;

	vector <int> A(n), B(n);
	for (int i = 0; i < n; i++)
		cin >> A[i];

	for (int i = 0; i < n; i++)
		cin >> B[i];

	sort(A.begin(), A.end());
	sort(B.begin(), B.end());

	int flag;
	for (int i = 0; i < n; i++)
	{
		flag = 0;
		for (int j = 0; j < n; j++)
		{
			if (mark[j])
				continue;

			if (A[i] + B[j] >= k)
			{
				mark[j] = 1;
				flag = 1;
				break;
			}
		}

		if (flag == 0)
			break;
	}

	if (flag)
		cout << "YES\n";

	else
		cout << "NO\n";

	return 0;
}