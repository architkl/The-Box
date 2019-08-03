#include <iostream>
#include <ctype.h>

using namespace std;

int s_count[52] = {0};
int t_count[52] = {0};

int main()
{
	string s, t;
	getline(cin, s);
	getline(cin, t);

	int len = s.length();
	for (int i = 0; i < len; i++)
	{
		if (isupper(s[i]))
			s_count[s[i] - 65]++;
		else
			s_count[s[i] - 71]++;
	}

	len = t.length();
	for (int i = 0; i < len; i++)
	{
		if (isupper(t[i]))
			t_count[t[i] - 65]++;
		else
			t_count[t[i] - 71]++;
	}

	int c_roll = 0, p_roll = 0;
	for (int i = 0; i < 26; i++)
	{
		//cout << t_count[i] << " " << s_count[i] << " " << t_count[i+26] << " " << s_count[i+26] << "\n";
		if (t_count[i] >= s_count[i])
		{
			c_roll += s_count[i];

			t_count[i] -= s_count[i];
			s_count[i] = 0;
		}
		else
		{
			c_roll += t_count[i];

			s_count[i] -= t_count[i];
			t_count[i] = 0;
		}

		if (t_count[i+26] >= s_count[i+26])
		{
			c_roll += s_count[i+26];

			t_count[i+26] -= s_count[i+26];
			s_count[i+26] = 0;
		}
		else
		{
			c_roll += t_count[i+26];

			s_count[i+26] -= t_count[i+26];
			t_count[i+26] = 0;
		}

		p_roll += min(s_count[i], t_count[i+26]) + min(s_count[i+26], t_count[i]);
	}

	cout << c_roll << " " << p_roll;

	return 0;
}