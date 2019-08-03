#include <iostream>
#include <vector>
#include <string>

using namespace std;

bool check(char a)
{
	switch(a)
	{
		case 'a':
		case 'e':
		case 'i':
		case 'o':
		case 'u':
		case 'A':
		case 'E':
		case 'I':
		case 'O':
		case 'U':
			return 1;
		default:
			return 0;
	}
}

int main()
{
	int T;
	cin >> T;
	cin.ignore();

	string s;
	int len, count, temp;
	for (int i = 0; i < T; i++)
	{
		getline(cin, s);

		len = s.length();
		count = 0;

		for (int i = 0; i < len; i++)
		{
			temp = 0;
			cout << i << " ";

			while (check(s[i]))
			{
				cout << s[i];
				temp++;
				i++;
			}
			cout << " ";

			if (temp > count)
				count = temp;
		}
		cout << "\n";

		if (count)
			cout << "YES " << count << "\n";

		else
			cout << "NO\n";
	}

	return 0;
}