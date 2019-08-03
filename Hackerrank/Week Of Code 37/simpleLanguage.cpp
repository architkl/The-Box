#include <iostream>

using namespace std;

int main()
{
	int n;
	cin >> n;

	string s;
	long long int y, g_max = 0;
	for (int i = 0; i < n; i++)
	{
		cin >> s >> y;

		if (s == "add")
		{
			if (y > 0)
				g_max += y;
		}

		else
		{
			if (y <= 0)
				continue;

			g_max = max(g_max, y);
		}
	}

	cout << g_max << "\n";

	return 0;
}