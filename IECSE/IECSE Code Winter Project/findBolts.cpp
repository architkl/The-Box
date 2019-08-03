#include <iostream>
#include <vector>

using namespace std;

int b_search(vector <int> v, int n, int e)
{
	int ul = n-1, ll = 0, mid;

	while (ll <= ul)
	{
		cout << ll << " " << ul << "\n";
		mid = ll + (ul - ll) / 2;

		if (v[mid] == e)
			return 1;

		else if (v[mid] > e)
			ul = mid - 1;

		else
			ll = mid + 1;
	}
	cout << ll << " " << ul << "\n";

	return 0;
}

int main()
{
	int T;
	cin >> T;

	int N, ele;
	for (int i = 0; i < T; i++)
	{
		cin >> N;

		vector <int> v(N);
		for (int j = 0; j < N; j++)
			cin >> v[j];

		cin >> ele;

		if (b_search(v, N, ele) == 1)
			cout << "Found\n";

		else
			cout << "Not Found\n";
	}

	return 0;
}