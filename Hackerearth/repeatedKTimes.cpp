#include <iostream>

using namespace std;

const int N_MAX = 100005;

int arr[N_MAX] = {};

int main()
{
	int n, k;
	cin >> n;

	int t;
	for (int i = 0; i < n; i++)
	{
		cin >> t;

		arr[t]++;
	}

	cin >> k;

	for (int i = 0; i < n; i++)
	{
		if (arr[i] == k)
		{
			cout << i << "\n";
			break;
		}
	}

	return 0;
}