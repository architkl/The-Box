#include <iostream>
#include <vector>

using namespace std;

int main()
{
	long long int N;
	int K;
	cin >> N >> K;

	vector <long long int> type(K);
	for (int i = 0; i < K; i++)
		cin >> type[i];

	int min = 0;
	for (int i = 1; i < K; i++)
	{
		if (N % type[i] < N % type[min])
			min = i;
	}

	cout << min + 1 << " " << N / type[min] << "\n";

	return 0;
}