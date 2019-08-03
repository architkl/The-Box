#include <fstream>
#include <vector>

using namespace std;

int main()
{
	ifstream fi("input.txt");
	ofstream fo("output.txt");

	int N;
	fi >> N;

	char op;
	int t;
	vector <int> stack;
	for (int i = 0; i < N; i++)
	{
		fi >> op;

		if (op == '+')
		{
			fi >> t;

			stack.push_back(t);
		}

		else
		{
			fo << stack.back() << "\n";

			stack.pop_back();
		}
	}

	fi.close();
	fo.close();

	return 0;
}