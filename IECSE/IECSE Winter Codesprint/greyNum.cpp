#include <iostream>

using namespace std;

int noOfBits(int n)
{
	int count = 0;
	while (n > 0)
	{
		n /= 2;
		count++;
	}

	return count;
}

void gray(int n, int code, int order)
{
	if (n == 1)
	{
		if (order == 1)
			cout << code << "\n" << code + 1 << "\n";
		else
			cout << code + 1 << "\n" << code << "\n";
		return;
	}

	if (order == 1)
	{
		gray(n-1, code * 2, 1);
		gray(n-1, (code + 1) * 2, -1);
	}
	else
	{
		gray(n-1, (code + 1) * 2, 1);
		gray(n-1, code * 2, -1);
	}
}

int main()
{
	int n;
	cin >> n;

	int bits = noOfBits(n);

	cout << bits << "\n";
	gray(bits, 0, 1);

	return 0;
}

/*
0000 - 0
0001 - 1
0011 - 3
0010 - 2
0110 - 6
0111 - 7
0101 - 5
0100 - 4
1100 - 12
1101 - 13
1111 - 15
1110 - 14
1010 - 10
1011 - 11
1001 - 9
1000 - 8
*/