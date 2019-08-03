#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	int n, k;
	cin >> n >> k;

	int t;
	vector <int> c;
	for (int i = 0; i < n; i++)
	{
		cin >> t;
		c.push_back(t);
	}

	sort(c.begin(), c.end());

	vector <int>::iterator it;
	int cost = 0, count = 0, x = 1;					//cost, count, multiplier
	for (it = c.end()-1; it != c.begin()-1; it--)
	{
		cost += *it * x;

		count++;
		if (count % k == 0)							//after each friend buying a flower increase multiplier
			x++;
	}

	cout << cost << "\n";

	return 0;
}