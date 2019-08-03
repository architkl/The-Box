#include <iostream>
#include <algorithm>

using namespace std;

int to_int(char a)
{
	return (int)a - 48;
}

int main()
{
	int T;
	cin >> T;

	string s, t;
	int st_0, st_1, len;
	for (int i = 0; i < T; i++)
	{
		cin >> s;
		len = s.length();
		t = s;

		st_0 = 0;
		st_1 = 0;

		//string starts with 0
		for (int j = 0; j < len; j++)
		{
			if (t[j] - 48 != j % 2)
			{
				st_0++;
				//t[j] = (j % 2) + 48;

				//cout << j << ":" << t[j] << " ";
			}
		}
		//cout << "\n";

		t = s;
		//string starts with 1
		for (int j = 0; j < len; j++)
		{
			if (t[j] - 48 == j % 2)
			{
				st_1++;
				//t[j] = !(j % 2) + 48;

				//cout << j << ":" << t[j] << " ";
			}
		}
		//cout << "\n";

		cout << min(st_0, st_1) << "\n";
	}

	return 0;
}