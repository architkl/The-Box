#include <iostream>

using namespace std;

int main()
{
	int n;
	cin >> n;

	string s;
	cin >> s;

	for (int i = 0; i < n; i++)
	{
		int dp[26] = {}, freq[26] = {};
		freq[s[i] - 97]++;
		
		for (int j = i + i; j < n; j++)
		{
			if (s[i] == s[j])
			{
				dp[i] += 
			}
		}
	}

	return 0;
}