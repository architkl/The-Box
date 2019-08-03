#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <climits>
#include <math.h>

#define pb push_back

using namespace std;

int main()
{
	int n;
	cin >> n;

	vector <long long int> price(n);
	map <long long int, long long int> mymap;
	for (int i = 0; i < n; i++)
	{
		cin >> price[i];
		mymap[price[i]] = price[i];
	}

	long long int min = LLONG_MAX;
	map <long long int, long long int>::iterator temp;

	for (int i = 0; i < n; i++)
	{
		temp = mymap.lower_bound(price[i]);

		while (temp != mymap.begin() && temp->first == price[i])
			temp--;

		if (temp->first == price[i])
			continue;

		if (price[i] - temp->first < min)
			min = price[i] - temp->first;

		mymap.erase(price[i]);
	}

	cout << min << "\n";

	return 0;
}