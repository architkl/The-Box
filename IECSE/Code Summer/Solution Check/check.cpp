#include <iostream>
#include <fstream>

using namespace std;

int main()
{
	ifstream f1("offOutput.txt", ios::in), f2("unoffOutput.txt", ios::in);

	string line1, line2;
	int f = 0;
	while (!f1.eof())
	{
		getline(f1, line1);
		getline(f2, line2);

		if (line1 != line2)
		{
			f = 1;
			cout << line1 << " " << line2 << "\n";
		}
	}

	if (f == 0)
		cout << "Same Output\n";

	f1.close();
	f2.close();

	return 0;
}