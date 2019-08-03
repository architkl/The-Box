#include <iostream>

using namespace std;

int main()
{
	string s;
	getline(cin, s);

	for (int i = 1; i < s.length(); i++)
	{
		if (s[i] == s[i-1] && i > 0)
		{
			s.erase(i-1, 2);
			i -= 2;
		}
	}

	if (s.length() == 0)
		cout << "Empty String";
	
	else
		cout << s;

	return 0;
}