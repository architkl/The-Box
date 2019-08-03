#include <iostream>
#include <stack>

using namespace std;

int main()
{
	string str;
	cin >> str;

	stack <int> S;

	int n = str.length(), a, b;
	for (int i = 0; i < n; i++)
	{
		if (str[i] == '+')
		{
			a = S.top();
			S.pop();
			b = S.top();
			S.pop();

			S.push(a + b);
		}

		else if (str[i] == '*')
		{
			a = S.top();
			S.pop();
			b = S.top();
			S.pop();

			S.push(a * b);
		}

		else
			S.push(int(str[i]) - 48);
	}

	cout << S.top() << "\n";

	return 0;
}