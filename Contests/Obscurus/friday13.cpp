#include <ctime>
#include <iostream>

using namespace std;

int main()
{
	int t;
	cin >> t;

	int d1, m1, y1, d2, m2, y2;

	while (t--)
	{
		cin >> d1 >> m1 >> y1 >> d2 >> m2 >> y2;

		int count = 0;

		if (y1 == y2)
		{
			for (int i = m1 - 1 + (d1 > 13); i < m2 + (d2 >= 13); i++)
			{
				tm t = {0, 0, 0, 13, i, y1 - 1900};

				time_t time_temp = mktime(&t);

				tm *time_out = localtime(&time_temp);

				if (time_out->tm_wday == 5)
					count++;
			}

			cout << count << "\n";

			continue;
		}

		for (int i = m1 - 1 + (d1 > 13); i < 12; i++)
		{
			tm t = {0, 0, 0, 13, i, y1 - 1900};

			time_t time_temp = mktime(&t);

			tm *time_out = localtime(&time_temp);

			if (time_out->tm_wday == 5)
				count++;
		}

		for (int i = y1+1; i < y2; i++)
		{
			for (int j = 0; j < 12; j++)
			{
				tm t = {0, 0, 0, 13, j, i - 1900};

				time_t time_temp = mktime(&t);

				tm *time_out = localtime(&time_temp);

				if (time_out->tm_wday == 5)
					count++;
			}
		}

		for (int i = 0; i < m2 - (d2 < 13); i++)
		{
			tm t = {0, 0, 0, 13, i, y2 - 1900};

			time_t time_temp = mktime(&t);

			tm *time_out = localtime(&time_temp);

			if (time_out->tm_wday == 5)
				count++;
		}

		cout << count << "\n";
	}

	return 0;
}