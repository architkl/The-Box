#include <iostream>
#include <string>

using namespace std;

int main()
{
	string s;
	getline(cin, s);

	for (int i = 0; i < s.length(); i++)
	{
		if (s[i] == '_')
		{
			while (s[i] == '_')
				s.erase(i, 1);

			s[i] &= ~32;
			continue;
		}

		s[i] |= 32;
	}

	cout << s;

	return 0;
}