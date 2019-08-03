#include <iostream>

using namespace std;

const int speed[] = {1, 2, 5, 10, 50, 100};

int main()
{
	int T;
	cin >> T;

	int X, t, index;
	for (int i = 0; i < T; i++)
	{
		cin >> X;

		t = 0;
		for (int i = 5; i >= 0; i--)
		{
			t += X / speed[i];
			X %= speed[i];
		}
		cout << t << "\n";
	}

	return 0;
}