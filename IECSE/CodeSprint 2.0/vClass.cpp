#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
	int q;
	cin >> q;

	vector <int> v(q);
	for (int i = 0; i < q; i++)
		cin >> v[i];

	int m = *max_element(v.begin(), v.end());

	int temp, parts[12] = {-1, -1, -1, -1, 1, -1, 1, -1, 2, 1, 2, -1};

	for (int i = 0; i < q; i++)
	{
		if (v[i] < 12)
			cout << parts[v[i]] << "\n";

		else if (v[i] % 2 == 0)
			cout << v[i] / 4 << "\n";

		else
			cout << (v[i] - 9) / 4 + 1 << "\n";
	}

	return 0;
}