#include <iostream>
#include <ctype.h>

using namespace std;
/*
char upper_nearest[] = {'C', 'C', 'C', 'C', 'C', 'G', 'G', 'G', 'I', 'I', 'I', 'M', 'M', 'M', 'O', 'O', 'O', 'S', 'S', 'S', 'S', 'S', 'Y', 'Y', 'Y', 'Y'};
char lower_nearest[] = {'a', 'a', 'a', 'e', 'e', 'e', 'g', 'g', 'g', 'g', 'k', 'k', 'k', 'm', 'm', 'm', 'q', 'q', 'q', 'q', 'q', 'q', 'q', 'q', 'q', 'q'};
*/

bool prime[200];

void sieve()
{
	for (int i = 2; i < 200; i++)
		prime[i] = 1;

	prime[0] = prime[1] = 0;
	
	for (int i = 2; i < 15; i++)
	{
		if (!prime[i])
			continue;

		for (int j = i*i; j < 200; j += i)
			prime[j] = 0;
	}
}

int main()
{
	sieve();

	int P;
	cin >> P;

	int n;
	string s;
	for (int i = 0; i < P; i++)
	{
		cin >> n >> s;

		for (int j = 0; j < n; j++)
		{
			if (!prime[s[j]])
			{
				int back = s[j] - 1, front = s[j] + 1;//cout << back << " " << front << "\n";

				while (!prime[back] && !prime[front])
				{
					//cout << back << " " << front << "\n";
					if (back > 0)
						back--;

					if (front < 122)
						front++;
				}

				if (prime[back])
					cout << char(back);

				else
					cout << char(front);
			}

			else
				cout << s[j];
		}

		cout << "\n";
	}

	return 0;
}