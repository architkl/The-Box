#include <iostream>
#include <ctype.h>

using namespace std;

int main()
{
	int n;
	cin >> n;

	string s;
	cin >> s;

	int add = 4;
	for (int i = 0; i < n; i++)
	{
		if (isdigit(s[i]))
		{
			add--;
			break;
		}
	}

	for (int i = 0; i < n; i++)
	{
		if (isupper(s[i]))
		{
			add--;
			break;
		}
	}

	for (int i = 0; i < n; i++)
	{
		if (islower(s[i]))
		{
			add--;
			break;
		}
	}

	for (int i = 0; i < n; i++)
	{
		if (s[i] >= 33 && s[i] <= 43)
		{
			add--;
			break;
		}
	}

	s.length() + add >= 6 ? cout << add << "\n" : cout << 6 - s.length() << "\n";

	return 0;
}