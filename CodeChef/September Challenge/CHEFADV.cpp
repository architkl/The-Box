#include <iostream>

using namespace std;

int main()
{
	int T;
	cin >> T;

	int N, M, X, Y;
	for (int i = 0; i < T; i++)
	{
		cin >> N >> M >> X >> Y;

		if (N == 1)
		{
			if (M == 1 || ((M-1) % Y == 0))
				cout << "Chefirnemo\n";

			else
				cout << "Pofik\n";
		}

		else if (M == 1)
		{
			if (/*N == 1 || */((N-1) % X == 0))
				cout << "Chefirnemo\n";

			else
				cout << "Pofik\n";	
		}

		else if (X == 1)
		{
			if ((M-1) % Y == 0 || (M-2) % Y == 0)
				cout << "Chefirnemo\n";

			else cout << "Pofik\n";
		}

		else if (Y == 1)
		{
			if ((N-1) % X == 0 || (N-2) % X == 0)
				cout << "Chefirnemo\n";

			else cout << "Pofik\n";
		}

		else if ((N-1) % X == 0)
		{
			if (/*M == 1 || */(M-1) % Y == 0)
				cout << "Chefirnemo\n";

			else
				cout << "Pofik\n";
		}

		else if (((N-2) % X == 0) && ((M-2) % Y == 0))
			cout << "Chefirnemo\n";

		else
			cout << "Pofik\n";
	}

	return 0;
}