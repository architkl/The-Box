#include <fstream>
#include <math.h>
#include <iomanip>

using namespace std;

#define sq(a) pow(a, 2)
#define mid(a, b) ((a + b) / 2)

double eucl_dist(double x1, double y1, double x2, double y2)
{
	return sqrt(sq(x1 - x2) + sq(y1 - y2));
}

int main()
{
	ifstream fi("input.txt");
	ofstream fo("output.txt");

	int a, b, c;
	fi >> a >> b >> c;

	fi.close();

	fo << setprecision(7) << fixed << (double)(a + b + c) / 6;

	fo.close();

	return 0;
}