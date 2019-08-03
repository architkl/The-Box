#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	int N;
	cin >> N;

	vector <int> a(10005);
	int t;
	for (int i = 0; i < N; i++)
	{
		cin >> t;
		a[t]++;
	}

	int streak = 0, temp;
	for (int i = 1; i <= 9999; i++)
	{
		temp = a[i] + a[i+1];

		if (temp > streak)
			streak = temp;
	}

	cout << streak;

	return 0;
}