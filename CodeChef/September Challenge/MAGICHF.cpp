#include <iostream>

using namespace std;

int main()
{
	int T;
	cin >> T;

	int N, X, S;
	for (int i = 0; i < T; i++)
	{
		cin >> N >> X >> S;

		int A, B;
		for (int j = 0; j < S; j++)
		{
			cin >> A >> B;

			if (A == X)
				X = B;

			else if (B == X)
				X = A;
		}

		cout << X << "\n";
	}

	return 0;
}