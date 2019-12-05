#include <iostream>
#include <map>
#include <string>

using namespace std;

int main()
{
	int n;
	cin >> n;

	map <string, string> name;
	map <string, int> i_max;

	string str;

	for (int i = 0; i < n; i++)
	{
		cin >> str;

		if (name[str] == str)
		{
			i_max[str]++;
			str += to_string(i_max[str]);
			name[str] = str;

			cout << str << "\n";
		}

		else
		{
			i_max[str] = 0;
			name[str] = str;

			cout << "OK\n";
		}
	}

	return 0;
}