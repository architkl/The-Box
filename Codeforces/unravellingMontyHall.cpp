#include <iostream>

using namespace std;

int main()
{
	int N;
	cin >> N;

	int x, win = 0;
	for (int i = 0; i < N; i++)
	{
		cin >> x;

		if (x != 1)
			win++;
	}

	cout << win << "\n";
}