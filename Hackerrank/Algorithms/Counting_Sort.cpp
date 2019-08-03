#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
	int n;
	cin >> n;

	vector <int> x(n);
	vector < vector <string> > s(100);
	
	string t;
	for (int i = 0; i < n; i++)
	{
		cin >> x[i];
		
		cin >> t;
		
		if (i < n/2)
			s[x[i]].push_back("-");
		
		else
			s[x[i]].push_back(t);
	}

	for (int i = 0; i < 100; i++)
	{
		for (int j = 0; j < s[i].size(); j++)
		{
			cout << s[i][j] << " ";
		}
	}


	return 0;
}