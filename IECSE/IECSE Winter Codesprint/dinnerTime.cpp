#include <iostream>

using namespace std;

int main()
{
	int n;
	cin >> n;

	if (n % 2 == 0 || n == 3)
		cout << "NO";

	else
		cout << "YES";

	return 0;
}