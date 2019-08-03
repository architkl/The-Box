#include <iostream>
#include <string>

using namespace std;

int search(string s, char e)
{
	for (auto i : s)
	{
		if (i == e)
			return 1;
	}

	return 0;
}

int main()
{
	int t;
	cin >> t;

	string s;
	for (int i = 0; i < t; i++)
	{
		cin >> s;

		for (int j = 65; j < 91; j++)
		{
			if (search(s, ((j/10) % 10) + 48))
			{
				//cout << char(((j/10) % 10) + 48);
				string t = s;
				t.erase(t.find(((j/10) % 10) + 48), 1);

				if (search(t, (j % 10) + 48))
				{
					cout << char(j);
				}
			}
		}

		cout << "\n";
	}

	return 0;
}