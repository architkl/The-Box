#include <iostream>
#include <vector>
#include <set>

using namespace std;

int main()
{
	int n;
	cin >> n;

	vector <int> x(n+1), y(n+1);
	for (int i = 0; i <= n; i++)
		cin >> x[i] >> y[i];

	set <double> slope;
	bool right = false;

	for (int i = 1; i <= n; i++)
	{
		if (x[0] == x[i])
		{
			right = true;
			continue;
		}

		slope.insert( double((y[0] - y[i])) / (x[0] - x[i]) );
	}

	right ? cout << slope.size() + 1 << "\n" : cout << slope.size() << "\n";

	return 0;
}