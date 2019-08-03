#include <iostream>
#include <math.h>

using namespace std;

int alpha[26] = {0};

void pall_2(long long int &sum)
{
	int temp;
	for (int i = 0; i < 26; i++)
	{
		temp = alpha[i] * (alpha[i] - 1) / 2;

		sum += temp;
		sum %= ((int)pow(10, 9) + 7);
	}
}

void pall_4(long long int &sum, string s, int len)
{
	for (int i = 0; i < len; i++)
	{
		for (int j = i + 1; j < len; j++)
		{
			for (int k = j + 1; k < len; k++)
			{
				if (s[j] == s[k])
				{
					for (int l = k + 1; l < len; l++)
					{
						if (s[i] == s[l])
						{
							sum++;
							sum %= ((int)pow(10, 9) + 7);
						}
					}
				}
			}
		}
	}
}

int main()
{
	string s;
	getline(cin, s);

	int len = s.length();
	for (int i = 0; i < len; i++)
		alpha[s[i] - 97]++;

	long long int sum = 0;
	pall_2(sum);
	pall_4(sum, s, s.length());

	cout << sum;

	return 0;
}