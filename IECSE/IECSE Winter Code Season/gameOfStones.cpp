#include <iostream>
#include <vector>

using namespace std;

const long long int LOW = -999999999;

int main()
{
	int n;
	cin >> n;

	vector <int> stone(n);
	for (int i = 0; i < n; i++)
		cin >> stone[i];

	long long int score = LOW, temp;
	for (int i = 1; i <= n; i++)
	{
		temp = 0;
		if (n % i)
			continue;

		int diag = min(i, n/i);
		for (int j = 0; j < diag; j++)
			temp += stone[j*i + j];

		if (temp > score)
			score = temp;
	}

	if (n == 0)
		cout << 0;

	else
		cout << score;

	return 0;
}