#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int T;
	cin >> T;

	int N;
	for (int i = 0; i < T; i++)
	{
		cin >> N;

		vector <int> y(N), z;
		for (int j = 0; j < N; j++)
		{
			cin >> y[j];

			if (y[j] % 2)
				z.push_back(y[j]);
		}

		if (z.size() % 2)
			cout << "No\n";

		else
			cout << "Yes\n";
	}

	return 0;
}