#include <iostream>
#include <string>

using namespace std;

int main()
{
	string s;
	getline(cin, s);

	int i = 0, n = s.length();
	while (s[i] != 'K' && i < n)
		i++;

	if (i == n)
		cout << i;

	else
	{
		int sum = 0, temp = 0, s1 = i, e1, s2 = i;
		while (i < n)
		{
			if (s[i] == 'K')
				temp++;
			else
				temp--;

			if (temp > sum)
			{
				sum = temp;
				s1 = s2;
				e1 = i;		
			}
			
			if (temp < 0)
			{
				temp = 0;
				s2 = i+1;
			}

			i++;
		}

		int count = 0, j = 0;
		for (; j < s1; j++)
			if (s[j] == 'R')
				count++;

		for (; j <= e1; j++)
			if (s[j] == 'K')
				count++;
		
		for (; j < n; j++)
			if (s[j] == 'R')
				count++;

		cout << count;
	}

	return 0;
}