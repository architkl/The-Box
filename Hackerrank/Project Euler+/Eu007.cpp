#include <iostream>
#include <vector>

using namespace std;

vector <int> prime;
int arr[1000005] = {};

void sieve()
{
	arr[0] = 0;
	arr[1] = 0;

	for (int i = 2; i < 1000005; i++)
		arr[i] = 1;

	for (int i = 2; i < 1002; i++)
	{
		if (arr[i] == 0)
			continue;

		for (int j = i*i; j < 1000005; j += i)
			arr[j] = 0;
	}

	for (int i = 0; i < 1000005; i++)
	{
		if (arr[i])
			prime.push_back(i);
	}
}

int main()
{
	sieve();

	int T;
	cin >> T;

	int N;
	for (int i = 0; i < T; i++)
	{
		cin >> N;

		cout << prime[N-1] << "\n";
	}

	return 0;
}