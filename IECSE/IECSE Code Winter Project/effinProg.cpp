#include <iostream>
#include <math.h>

using namespace std;
/*
int in_A(long long int x)
{
	int D = sqrt(1 + 8*x);

	if (D == sqrt(1 + 8*x))
		if ( (D-1) % 2 == 0)
			return 1;

	return 0;
}

int in_B(long long int x)
{
	int D = sqrt(1 + 24*x);

	if (D == sqrt(1 + 24*x))
		if ( (D+1) % 6 == 0)
			return 1;

	return 0;
}

int in_C(long long int x)
{
	int D = sqrt(1 + 8*x);

	if (D == sqrt(1 + 8*x))
		if ( (D+1) % 4 == 0)
			return 1;

	return 0;
}
*/

long long int A(long long int x)
{
	return x*(x+1)/2;
}

long long int B(long long int x)
{
	return x*(3*x-1)/2;
}

long long int C(long long int x)
{
	return x*(2*x-1);
}

int main()
{
	long long int M, N;
	short int a, b;
	cin >> M >> N >> a >> b;

	if (a == 3)
	{
		long long int i = 1, j = 1, t1 = 1, t2 = 1;

		while (t1 <= M)
		{
			i++;
			t1 = A(i);
		}

		while (t2 <= M)
		{
			j++;
			t2 = B(j);
		}

		while (t1 < N && t2 < N)
		{
			t1 = A(i);
			t2 = B(j);

			if (t1 == t2)
			{
				cout << t1 << "\n";
				i++;
				j++;
			}

			else if (t1 < t2)
				i++;

			else
				j++;
		}
	}

	else
	{
		long long int i = 1, j = 1, t1 = 1, t2 = 1;

		while (t1 <= M)
		{
			i++;
			t1 = B(i);
		}

		while (t2 <= M)
		{
			j++;
			t2 = C(j);
		}
		
		while (t1 < N && t2 < N)
		{
			t1 = B(i);
			t2 = C(j);

			if (t1 == t2)
			{
				cout << t1 << "\n";
				i++;
				j++;
			}

			else if (t1 < t2)
				i++;

			else
				j++;
		}	
	}

	return 0;
}

/*
0 = n^2 + n - 2x
n = ( -1 +- ( sqrt(1 + 8x) ) ) / 2

3n^2 - n - 2x = 0
n = ( 1 +- ( sqrt(1 + 24x) ) ) / 6

2n^2 - n -x = 0
n = ( 1 +- ( sqrt(1 + 8x) ) ) / 4
*/