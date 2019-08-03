#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	int na, nb, k, m;
	cin >> na >> nb >> k >> m;

	vector <int> a(na), b(nb);
	for (int i = 0; i < na; i++)
		cin >> a[i];

	for (int i = 0; i < nb; i++)
		cin >> b[i];

	sort(a.begin(), a.end());
	sort(b.begin(), b.end());

	a[k-1] < b[nb-m] ? cout << "YES\n" : cout << "NO\n";

	return 0;
}