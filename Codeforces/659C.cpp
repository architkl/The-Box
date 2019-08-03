#include <iostream>
#include <vector>
#include <map>

using namespace std;

map <int, int> mp;

int main()
{
	int n, m;
	cin >> n >> m;

	vector <int> A(n);
	for (int i = 0; i < n; i++)
	{
		cin >> A[i];
		mp[A[i]]++;
	}

	long long int sum = 0;
	int count = 0;
	vector <int> toys;
	for (int i = 1; i <= 1e9; i++)
	{
		if (mp[i])
			continue;

		if (sum + i > m)
			break;

		sum += i;
		count++;
		toys.push_back(i);
	}

	cout << count << "\n";

	vector <int>::iterator it = toys.begin();
	for (; it != toys.end(); it++)
		cout << *it << " ";

	return 0;
}