#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	ifstream fi("input.txt");
	ofstream fo("output.txt");

	int n;
	fi >> n;

	vector <int> t(n);
	for (int i = 0; i < n; i++)
		fi >> t[i];

	const int T_MAX = 18000;

	sort(t.begin(), t.end());
	
	int t_cur = 0, i = 0;

	while (i < n && t_cur + t[i] <= T_MAX)
		t_cur += t[i++];

	fo << i;

	fi.close();
	fo.close();

	return 0;
}