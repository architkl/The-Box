#include <iostream>
#include <iomanip>
#include <math.h>

using namespace std;

const int threshold = 90;

int main()
{
	int n;
	cin >> n;

	int count = 0, t;
	float avg = 0;
	for (int i = 0; i < n; i++)
	{
		cin >> t;

		if (t >= threshold)
		{
			avg += t;
			count++;
		}
	}

	avg /= count;
	int temp = avg * 1000, rem;
	rem = temp % 10;
	if (rem >= 5)
	{
		temp /= 10;
		temp++;
		avg = (float)temp / 100;
	}

	else if (rem == 4)
	{
		int i = 4;
		while (rem == 4)
		{
			temp = avg * pow(10, i);
			rem = temp % 10;
			i++;
		}

		if (rem >= 5)
		{
			temp = avg * 100 + 1;
			avg = (float)temp / 100;
		}

		else
		{
			temp = avg * 100;
			avg = (float)temp / 100;
		}
	}

	else
	{
		temp /= 10;
		avg = (float)temp / 100;
	}

	cout << setprecision(2) << fixed << avg << "\n";
	
	/*
	int temp = (int)(avg * 1000);
	//cout << temp << "\n";

	if (temp % 10 >= 5)
	{
		temp /= 10;
		temp++;
		avg = (float)temp / 100;
	}

	else
	{
		temp /= 10;
		avg = (float)temp / 100;
		//cout << temp << " " << avg << "\n";
	}

	cout << setprecision(2) << fixed << avg << "\n";*/

	return 0;
}