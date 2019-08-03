#include <iostream>
#include <set>

using namespace std;

int main()
{
	int Q;
	cin >> Q;

	multiset <int> S;
	multiset <int>::iterator it;

	int ch, X, temp;
	for (int i = 0; i < Q; i++)
	{
		cin >> ch;

		switch (ch)
		{
			case 1:
				cin >> X;
				
				S.insert(X);
				break;

			case 2:
				cin >> X;

				it = S.find(X);
				if (it == S.end())
				{
					cout << -1 << "\n";
					break;
				}

				S.erase(it);
				break;

			case 3:
				if (S.empty())
				{
					cout << -1 << "\n";
					break;
				}

				cout << *S.rbegin() << "\n";
				break;

			case 4:
				if (S.empty())
				{
					cout << -1 << "\n";
					break;
				}

				cout << *S.begin() << "\n";
				break;
		}
	}

	return 0;
}