#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
	int N, X;
	cin >> N >> X;

	vector <int> A(N);
	for (int i = 0; i < N; i++)
	{
		cin >> A[i];

		if (A[i] <= X)
			A[i] = 1;

		else
			A[i] = 0;
	}

	/*for (int i = 0; i < N; i++)
		cout << A[i] << " ";
	cout << "\n";*/

	int sum = 0, i = 0;
	while (A[i] && i < N)
	{
		sum++;
		i++;
	}
	i++;

	while (A[i] && i < N)
	{
		sum++;
		i++;
	}

	cout << sum;

	/*
	int g_max = 0, l_max;
	for (int i = 0; i < N; i++)
	{
		l_max = 0;
		 while (A[i] == 1 && i < N)
		 {
		 	l_max++;
		 	//cout << i << " ";
		 	i++;
		 }
		 int j = i + 1;

		 while (A[j] == 1 && j < N)
		 {
		 	l_max++;
		 	//cout << j << " ";
		 	j++;
		 }
		 //cout << "\n";
		 g_max = max(g_max, l_max);
	}

	cout << g_max;*/

	return 0;
}

/*
7 6
4 3 7 6 7 2 2
1 0 1 1 0 1 1
0 0 0 0 0 0 0
*/