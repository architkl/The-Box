#include <iostream>
#include <stack>

using namespace std;

int main()
{
	int T;
	cin >> T;

	string str;
	for (int i = 0; i < T; i++)
	{
		cin >> str;

		stack <char> S;
		int n = str.length();
		char c;

		for (int j = 0; j < n; j++)
		{
			if (S.empty() == true)
			{
				S.push(str[j]);
				continue;
			}

			c = S.top();

			if (c == '.' && str[j] == '#')
				S.pop();

			else if (c == '+' && str[j] == '-')
				S.pop();

			else
				S.push(str[j]);
		}

		if (S.empty() == true)
			cout << "Valid\n";

		else
			cout << "Not Valid\n";
	}

	return 0;
}