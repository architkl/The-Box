#include <iostream>
#include <Vector>

using namespace std;

int main()
{
	int t;
	cin >> t;

	int freq[26];
	for (int i = 0; i < t; i++)
	{
		for (int j = 0; j < 26; j++)
			cin >> freq[j];
	}

	return 0;
}