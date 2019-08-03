#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

const int max_int = 1000000000;

int main()
{
	int n, k;
	cin >> n >> k;

	vector <int> integer;
	int t;
	for (int i = 0; i < n; i++)
	{
		cin >> t;
		integer.push_back(t);
	}

	sort(integer.begin(), integer.end());

	vector <int>::iterator it;
	int min = max_int;
	for (it = integer.begin(); it != integer.end()-k+1; it++)
	{
		if (*(it+k-1) - *it < min)
			min = *(it+k-1) - *it;
	}

	cout << min << "\n";

	return 0;
}