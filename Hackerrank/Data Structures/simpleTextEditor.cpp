#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main()
{
	int Q;
	cin >> Q;
	cin.ignore();

	stack <int> operation;
	string S;
	int type, k;
	string W;
	for (int i = 0; i < Q; i++)
	{
		cin >> type;
		operation.push(type);

		if (type == 1)
		{
			getline(cin, W);
			S += W;
		}

		else if (type == 2)
		{
			cin >> k;
			cin.ignore();

			S.erase(S.end()-k, S.end());
		}

		else if (type == 3)
		{
			cin >> k;
			cin.ignore();

			cout << S[k];
		}

		else
		{
			//undo
		}
	}

	return 0;
}