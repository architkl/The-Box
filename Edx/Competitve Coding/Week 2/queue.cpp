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
	int t, front = 0;
	vector <int> queue;
	for (int i = 0; i < N; i++)
	{
		fi >> op;

		if (op == '+')
		{
			fi >> t;

			queue.push_back(t);
		}

		else
		{
			fo << queue[front] << "\n";

			front++;
		}
	}

	fi.close();
	fo.close();

	return 0;
}