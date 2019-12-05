#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int n;
	cin >> n;

	vector <int> v(n+1);
	for (int i = 1; i <= n; i++)
		cin >> v[i];

	bool love_tri = 0;
	for (int i = 1; i <= n-2; i++)
	{
		if (i == v[v[v[i]]])
		{
			love_tri = 1;
			break;
		}
	}

	if (love_tri)
		cout << "YES\n";

	else
		cout << "NO\n";

	return 0;
}