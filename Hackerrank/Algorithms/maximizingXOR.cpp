#include <iostream>

using namespace std;

int main()
{
	int L, R;
	cin >> L >> R;

	int x = 0, temp;
	for (int i = L; i <= R; i++)
	{
		for (int j = i; j <= R; j++)
		{
			temp = i^j;

			if (temp > x)
				x = temp;
		}
	}

	cout << x;

	return 0;
}