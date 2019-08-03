#include <iostream>
#include <fstream>
#include <stack>

using namespace std;

int main()
{
	ifstream fi("input.txt");
	ofstream fo("output.txt");

	int N;
	fi >> N;

	char op;
	int t;
	stack <int> S1, S2;

	for (int i = 0; i < N; i++)
	{
		fi >> op;

		if (op == '+')
		{
			fi >> t;
			S1.push(t);
		}

		else if (op == '-')
		{
			while (!S1.empty())
				S2.push(S1.pop());
			
			S2.pop();

			while(!S2.empty())
				S1.push(S2.pop());
		}

		else
			fo << myQ[mn] << "\n";
	}

	return 0;
}