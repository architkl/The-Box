#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	int T;
	cin >> T;

	int N;
	for (int i = 0; i < T; i++)
	{
		cin >> N;

		vector <int> v(N);
		for (int j = 0; j < N; j++)
			cin >> v[j];

		sort(v.begin(), v.end());

		int diff = v[1] - v[0], temp = 1000000007;
		for (int j = 1; j < N-1; j++)
		{
			temp = v[j+1] - v[j];

			if (temp < diff)
				diff = temp;
		}

		cout << diff << "\n";
	}

	return 0;
}