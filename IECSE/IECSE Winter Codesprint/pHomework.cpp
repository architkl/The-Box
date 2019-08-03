#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

int alpha[26] = {0};
vector <int> occ[26];

int min_4(int a, int b, int c, int d)
{
	return min(min(a, b), min(c, d));
}

int max_4(int a, int b, int c, int d)
{
	return max(max(a, b), max(c, d));
}

void pall_2(long long int &sum)
{
	int temp;
	for (int i = 0; i < 26; i++)
	{
		temp = alpha[i] * (alpha[i] - 1) / 2;

		sum += temp;
		sum %= ((int)pow(10, 9) + 7);
	}
}

void pall_4(long long int &sum, string s, int len)
{
	for (int i = 0; i < len; i++)
	{
		for (int j = i+1; j < len; j++)
		{
			int k = 0;
			while (occ[s[j] - 97][k] < j && k < occ[s[j] - 97].size())
				k++;

			if (k == occ[s[j] - 97].size())
				continue;

			int l = 0;
			while (occ[s[i] - 97][l] < occ[s[j] - 97][k] && l < occ[s[i] - 97].size())
				l++;

			if (l == occ[s[i] - 97].size())
				continue;
		}
	}
}

int main()
{
	string s;
	getline(cin, s);

	int len = s.length();
	for (int i = 0; i < len; i++)
	{
		alpha[s[i] - 97]++;
		occ[s[i] - 97].push_back(i);
	}

	long long int sum = 0;
	pall_2(sum);
	pall_4(sum, s, s.length());

	/*
	for (int i = 0; i < 26; i++)
	{
		for (int j = 0; j < occ[i].size(); j++)
		{
			cout << occ[i][j] << " ";
		}
		cout << "\n";
	}*/

	cout << sum;

	return 0;
}