#include <iostream>
#include <fstream>
#include <math.h>

using namespace std;

int main()
{
	ifstream fi("input.txt");
	ofstream fo("output.txt");

	int K;
	fi >> K;
	//cin >> K;

	int div[10000005] = {};

	int n = K / 2;
	for (int i = 2; i <= n; i++)
	{
		//cout << i << ": ";
		for (int j = 2*i; j <= K; j += i)
		{
			//cout << j << " ";
			div[j]++;
		}
		//cout << "\n";
	}

	int mx = 2;
	for (int i = 3; i <= K; i++)
	{
		if (div[i] > div[mx])
			mx = i;
	}

	//cout << K - mx + 1;
	fo << K - mx + 1;

/*
	for (int i = 0; i <= K; i++)
		cout << div[i]+2 << "\n";*/

	fi.close();
	fo.close();

	return 0;
}