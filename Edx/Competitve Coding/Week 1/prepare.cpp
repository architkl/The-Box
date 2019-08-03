#include <fstream>
#include <vector>

using namespace std;

int main()
{
	ifstream fi("input.txt");
	ofstream fo("output.txt");

	int n;
	fi >> n;

	vector <int> p(n), t(n);
	for (int i = 0; i < n; i++)
		fi >> p[i];

	for (int i = 0; i < n; i++)
		fi >> t[i];
	
	int ans = 0, pf = 0, tf = 0;
	for (int i = 0; i < n; i++)
	{
		if (p[i] > t[i])
		{
			ans += p[i];
			pf++;
		}

		else
		{
			ans += t[i];
			tf++;
		}
	}

	if (pf == 0 || tf == 0)
	{
		vector <int> diff(n);
		for (int i = 0; i < n; i++)
			diff[i] = p[i] - t[i];

		if (pf == 0)
		{
			int mx = 0;

			for (int i = 1; i < n; i++)
			{
				if (diff[i] > diff[mx])
					mx = i;
			}

			ans += diff[mx];
		}

		else
		{
			int mn = 0;

			for (int i = 1; i < n; i++)
			{
				if (diff[i] < diff[mn])
					mn = i;
			}

			ans -= diff[mn];
		}
	}

	fo << ans << "\n";

	fi.close();
	fo.close();

	return 0;
}