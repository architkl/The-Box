#include <iostream>
#include <vector>

using namespace std;

const int N_MAX = 100000;

vector <int> S[N_MAX];

int main()
{
	int N, Q;
	cin >> N >> Q;

	int x, y, q, lastAnswer = 0, t;
	for (int i = 0; i < Q; i++)
	{
		cin >> q >> x >> y;

		t = (x ^ lastAnswer) % N;

		if (q == 1)
			S[t].push_back(y);

		else
		{
			lastAnswer = S[t][y % S[t].size()];
			cout << lastAnswer << "\n";
		}
	}

	return 0;
}