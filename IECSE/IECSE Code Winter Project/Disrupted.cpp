#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

void initialize(short int arr[])
{
	for (int i = 0; i < 33; i++)
		arr[i] = 0;
}

void to_bin(short int arr[], long long int n)
{
	int i = 1;
	while (n != 0)
	{
		arr[i] = n % 2;
		n /= 2;
		i++;
	}
}

int main()
{
	int T;
	cin >> T;

	vector <long long int> a(T), b(T);
	for (int i = 0; i < T; i++)
		cin >> a[i] >> b[i];


	short int num1[33], num2[33], ans[33];
	long long int sum;
	for (int i = 0; i < T; i++)
	{
		initialize(num1);
		initialize(num2);
		initialize(ans);
		sum = 0;

		to_bin(num1, a[i]);
		to_bin(num2, b[i]);

		int carry = 0, temp;
		for (int i = 32; i >= 0; i--)
		{
			temp = num1[i] + num2[i] + carry;
			ans[i] = temp % 2;
			carry = temp / 2;

			sum += ans[i] * pow(2, 32-i);
		}

		cout << sum << "\n";
	}

	return 0;
}