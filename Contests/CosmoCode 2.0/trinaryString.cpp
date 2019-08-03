#include <iostream>
#include <ctype.h>

using namespace std;

int main()
{
	int t;
	cin >> t;

	string s;
	for (int i = 0; i < t; i++)
	{
		cin >> s;

		for (int j = 0; j < s.length(); j++)
		{
			if (isupper(s[j]))
				s[j] = '0';

			else if(islower(s[j]))
				s[j] = '1';

			else
				s[j] = '2';
		}

		cout << s << "\n";
	}

	return 0;
}