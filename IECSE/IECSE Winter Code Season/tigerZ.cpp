#include <iostream>

using namespace std;

int main()
{
	int T;
	cin >> T;

	long long int N, M, k;
	for (int i = 0; i < T; i++)
	{
		cin >> N >> M >> k;

        (k - 1 + M) % N ? cout << (k - 1 + M) % N << "\n" : cout << N << "\n";
	}

	return 0;
}