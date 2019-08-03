#include <iostream>
#include <math.h>

using namespace std;

int main()
{
	int q;
	cin >> q;

	long long int S, l, b, h, vol;
	for (int i = 0; i < q; i++)
	{
		cin >> S;

		l = (S / 3);
		S -= l;
		b = S / 2;
		h = S - b;

		l %= ((int)pow(10, 9) + 7);
		b %= ((int)pow(10, 9) + 7);
		h %= ((int)pow(10, 9) + 7);

		vol = (l * b) % ((int)pow(10, 9) + 7);
		vol *= h;
		vol %= ((int)pow(10, 9) + 7);

		cout << vol << "\n";
	}

	return 0;
}