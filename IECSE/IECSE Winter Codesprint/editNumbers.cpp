#include <iostream>

using namespace std;

int main()
{
	int n, k, q;
	cin >> n >> k >> q;

	int bin[32], size = 0;
	while (n != 0)
	{
		bin[size++] = n % 2;
		n >>= 1;
	}
	bin[k-1] ^= 1;
	bin[q-1] = 1;

	int m = 0;
	for (int i = size-1; i >= 0; i--)
	{
		m *= 2;
		m += bin[i];
	}

	cout << m;

	return 0;
}