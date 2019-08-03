#include <iostream>
#include <stack>

using namespace std;

int main()
{
	int N;
	cin >> N;

	int x, type;
	stack <int> S, mx;
	for (int i = 0; i < N; i++)
	{
		cin >> type;

		if (type == 1)
		{
			cin >> x;

			S.push(x);

			if (mx.empty() || x >= mx.top())
				mx.push(x);
		}

		else if (tpye == 2)
		{
			if (mx.top() == S.top())
				mx.pop();
			
			S.pop();
		}

		else
			cout << mx.top() << "\n";
	}

	return 0;
}