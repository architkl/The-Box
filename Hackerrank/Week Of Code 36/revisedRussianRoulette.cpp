#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int n;
	cin >> n;

	int max_op = 0;
	vector <int> doors(n);
	for (int i = 0; i < n; i++)
	{
		cin >> doors[i];

		if (doors[i])
			max_op++;
	}

	int min_op = 0;
	for (int i = 0; i < n; i++)
	{
		if (doors[i] == 0)
			continue;

		else
		{
			min_op++;
			i++;
		}
	}

	cout << min_op << " " << max_op << "\n";

	return 0;
}