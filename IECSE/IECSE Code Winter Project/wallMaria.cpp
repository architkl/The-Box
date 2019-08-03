#include <iostream>
#include <math.h>

using namespace std;

int height(int x)
{
	int D = sqrt(1 + (long long)8*x);

	return ((-1 + D) / 2);
}

int main()
{
	int T;
	cin >> T;

	int N;
	for (int i = 0; i < T; i++)
	{
		cin >> N;

		cout << height(N) << "\n";
	}
}

/*
n(n+1) = 2x
n2 + n - 2x = 0
n = (-1 + sqrt(1 + 8x)) / 2
*/