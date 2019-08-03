#include <iostream>
#include <math.h>

using namespace std;

int main()
{
	int n;
	cin >> n;

	int arr[n];
	for (int i = 0; i < n; i++)
		cin >> arr[i];

	int highest = 0, lowest = 0, width = 0, temp = 0;
	for (int i = 0; i < n; i++)
	{
		temp += arr[i] * pow(-1, i % 2);
		width += arr[i];

		if (temp > highest)
			highest = temp;

		else if (temp < lowest)
			lowest = temp;
	}

	int height = highest-lowest;
	char pattern[height][width];
	for (int i = 0; i < height; i++)
		for (int j = 0; j < width; j++)
			pattern[i][j] = ' ';

	int y = highest - 1, x = 0;
	for (int i = 0; i < n; i++)
	{
		if (i % 2 == 0)
		{
			pattern[y][x] = '/';
			for (int j = 1; j < arr[i]; j++)
			{
				y--;
				x++;
				pattern[y][x] = '/';
			}
			x++;
		}

		else
		{
			pattern[y][x] = '\\';
			for (int j = 1; j < arr[i]; j++)
			{
				y++;
				x++;
				pattern[y][x] = '\\';
			}
			x++;
		}
	}

	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j++)
			cout << pattern[i][j];
		cout << "\n";
	}

	return 0;
}