#include <iostream>

using namespace std;

string acidNaming(string s)
{
	int len = s.length();

	if (s[len-2] == 'i' && s[len-1] == 'c')
	{
		if ((s[0] == 'h' && s[1] == 'y') && (s[2] == 'd' && s[3] == 'r') && s[4] == 'o')
			return "non-metal acid";

		else
			return "polyatomic acid";
	}

	else
		return "not an acid";
}

int main()
{
	int q;
	cin >> q;

	cin.ignore();

	string s;
	for (int i = 0; i < q; i++)
	{
		getline(cin, s);

		cout << acidNaming(s) << "\n";
	}

	return 0;
}