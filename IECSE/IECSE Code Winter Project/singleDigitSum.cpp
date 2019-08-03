#include <iostream>

using namespace std;

int sum(int n)
{
	if (n == 0)
		return 0;

	int t = n%10 + sum(n/10);
	
	if (t / 10 != 0)
		return sum(t);
	else
		return t;
}

int main()
{
	int n;
	cin >> n;

	cout << sum(n);

	return 0;
}