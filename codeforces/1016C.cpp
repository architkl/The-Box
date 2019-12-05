#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int n;
	cin >> n;

	vector < vector <int> > shroom(2, vector <int> (n));
	for (int i = 0; i < n; i++)
		cin >> shroom[0][i];

	for (int i = 0; i < n; i++)
		cin >> shroom[1][i];

	return 0;
}