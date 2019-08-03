#include <iostream>
#include <string>

using namespace std;

int count[26];

void ini()
{
	for (int i = 0; i < 26; i++)
		count[i] = 0;
}

int main()
{
	int T;
	cin >> T;

	int N, flag;
	string S;
	for (int i = 0; i < T; i++)
	{
		cin >> N;

		cin.ignore();
		getline(cin, S);

		ini();
		flag = 0;
		for (int i = 0; i < N; i++)
			count[S[i] - 97]++;

		for (int i = 0; i < 26; i++)
		{
			if (count[i] % 2)
			{
				flag = 1;
				break;
			}
		}

		if (flag)
			cout << -1;

		else
		{
			int half, j;
			for (int i = 0; i < 26; i++)				//print first half of pallindrome
			{
				half = count[i] / 2;
				j = 0;

				while (j < half)
				{
					cout << char(i + 97);
					j++;
				}
			}

			for (int i = 25; i >= 0; i--)				//print second half of pallindrome
			{
				j = count[i] / 2;
				while (j > 0)
				{
					cout << char(i + 97);
					j--;
				}	
			}
		}

		cout << "\n";
	}

	return 0;
}