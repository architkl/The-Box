#include <iostream>

using namespace std;

int strength[26];

void in_stren()
{
	for (int i = 0; i < 26; i++)
		cin >> strength[i];
}

int main()
{
	in_stren();

	int T;
	cin >> T;

	int k;
	string s;
	for (int i = 0; i < T; i++)
	{
		cin.ignore();
		getline(cin, s);

		cin >> k;

		int len = s.length(), sum = 0;
		for (int i = 0; i < len; i++)
			sum += strength[s[i] - 97];

		int flag = 0;
		for (int i = 0; i < len; i++)
		{
			if (sum - strength[s[i] - 97] == k)
			{
				flag = 1;
				cout << i << "\n";
				break;
			}
		}

		if (!flag)
			cout << "-1\n";
	}

	return 0;
}