#include <iostream>
#include <fstream>

using namespace std;

int main()
{
	ifstream fi("input.txt");
	ofstream fo("output.txt");

	long long int A, B;
	fi >> A >> B;

	fo << A + B * B << "\n";

	fi.close();
	fo.close();

	return 0;
}