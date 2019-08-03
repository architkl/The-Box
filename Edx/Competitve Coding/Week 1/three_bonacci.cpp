#include <iostream>
#include <fstream>

using namespace std;

int main()
{
	ifstream fi("input.txt");
	ofstream fo("output.txt");

	int A0, A1, A2, n;
	fi >> A0 >> A1 >> A2 >> n;

	int An;

	if (n == 0)
		fo << A0 << "\n";

	else if (n == 1)
		fo << A1 << "\n";

	else if (n == 2)
		fo << A2 << "\n";

	else
	{
		for (int i = 3; i <= n; i++)
		{
			An = A2 + A1 - A0;
			A0 = A1;
			A1 = A2;
			A2 = An;
		}

		fo << An << "\n";
	}

	fi.close();
	fo.close();

	return 0;
}