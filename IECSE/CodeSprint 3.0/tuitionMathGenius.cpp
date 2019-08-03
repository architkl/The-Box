#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool mycomp(char i, char j)
{
	return (i > j);
}

int sod(string s)
{
	int sum = 0;
	for (int i = 0; i < s.length(); i++)
	{
		sum += int(s[i] - 48);
	}

	return sum;
}

int main()
{
	int t;
	cin >> t;

	string L;
	for (int i = 0; i < t; i++)
	{
		cin >> L;

		string s = L, t;
		vector <string> v;
		for (int j = 0; j < s.length(); j++)
		{
			t = s;
			t.erase(j, 1);
			v.push_back(t);
		}

		sort(v.begin(), v.end(), mycomp);

		int f = 0;
		for (int j = 0; j < v.size(); j++)
		{
			if (sod(v[j]) % 3 == 0 && v[j][v[j].length()-1])
			{
				cout << v[j] << "\n";
				f = 1;
				break;
			}
		}

		if (f == 0)
			cout << -1 << "\n";
	}

	return 0;
}