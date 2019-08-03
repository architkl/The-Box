#include <iostream>
#include <vector>

using namespace std;
/*
void decodeArray(vector <int> C)
{
	int x = (1 << 16) - 1, n = C.size();
	
	//vector <int> A(n), B(n);

	for (int i = 0; i < n; i++)
		cout << (C[i] & x) << " ";

	cout << "\n";

	for (int i = 0; i < n; i++)
		cout << (C[i] >> 16) << " ";

	cout << "\n";

	/*for (int i = 0; i < n; i++)
		cout << A[i] << " ";
	
	cout << "\n";

	for (int i = 0; i < n; i++)
		cout << B[i] << " ";

	cout << "\n";/
}*/

int main()
{
	int T;
	cin >> T;

	int n, x = (1 << 16) - 1;
	for (int i = 0; i < T; i++)
	{
		cin >> n;

		vector <long long int> A(n);
		for (int j = 0; j < n; j++)
			cin >> A[j];

		cout << "Case " << i + 1 << ":\n";
		for (int j = 0; j < n; j++)
			cout << (A[j] & x) << " ";

		cout << "\n";

		for (int j = 0; j < n; j++)
			cout << (A[j] >> 16) << " ";

		cout << "\n";

		//decodeArray(A);
	}

	return 0;
}