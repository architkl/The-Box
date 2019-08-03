#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main()
{
	int n;
	cin >> n;

	cin.ignore();

	string s;
	for (int i = 0; i < n; i++)
	{
		getline(cin, s);

		stack <char> st;
		int len = s.length();
		char c;

		for (int j = 0; j < len; j++)
		{
			if ( (s[j] == '[' || s[j] == '{') || s[j] == '(')
				st.push(s[j]);

			else
			{
				if (st.empty())
				{
					st.push('(');
					break;
				}
				c = st.top();

				if ( (s[j] == ']' && c != '[') || (s[j] == '}' && c != '{') || (s[j] == ')' && c != '(') )
					break;

				st.pop();
			}
		}

		if (st.empty())
			cout << "YES\n";

		else
			cout << "NO\n";
	}

	return 0;
}