#include <iostream>

using namespace std;

int num[17] = {9}, size = 1;

void init()
{
	num[0] = 9;
	for (int i = 1; i < 17; i++)
		num[i] = 0;

	size = 1;
}

long long int calc()
{
	long long int n = 0;
	for (int i = size-1; i >= 0; i--)
	{
		n *= 10;
		n += num[i];
	}

	return n;
}

int main()
{
	int T;
	cin >> T;

	int n;
	long long int multiple;
	for (int i = 0; i < T; i++)
	{
		cin >> n;
		init();

		multiple = calc();
		while (multiple % n)
		{
			int j = 0;
			while (num[j++] != 0);
			j--;

			num[j] = 9;
			if (j == size)
				size++;
			
			j--;
			while (j >= 0)
			{
				num[j] = 0;
				j--;
			}

			multiple = calc();
		}

		cout << multiple << "\n";
	}

	return 0;
}