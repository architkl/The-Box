#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

int main()
{
	long long int n, k;
	cin >> n >> k;

	vector <long long int> A(n);
	for (int i = 0; i < n; i++)
		cin >> A[i];

	int mx = 0, mn = 0;
	for (int i = 1; i < n; i++)
	{
		if (A[i] > A[mx])
			mx = i;

		else if (A[i] < A[mn])
			mn = i;
	}

	//cout << A[mx] << " " << A[mn] << "\n";

	double x, y;

	if (A[mx] == A[mn])
	{
		if (A[mx] == k)
			x = 1;

		else
			x = -1;
	}

	else
		x = (double)(k - A[mn]) / (A[mx] - A[mn]);

	y = 1 - x;

	if ( (x >= 0 && x <= 1) && (y >= 0 && y <= 1) )
	{
		vector <double> B(n);
		B[mx] = x;
		B[mn] = y;

		for (int i = 0; i < n; i++)
			cout << setprecision(10)<< fixed << B[i] << " ";
	}

	else
		cout << -1;

	cout << "\n";

	return 0;
}