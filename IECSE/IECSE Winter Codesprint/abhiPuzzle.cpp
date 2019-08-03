#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

int main()
{
	int n;
	cin >> n;

	vector <int> v(n);
	for (int i = 0; i < n; i++)
			cin >> v[i];
	
	long long int left[n], right[n];
	left[0] = right[n-1] = 1;
	for (int i = 1; i < n; i++)
	{
		left[i] = left[i-1] * v[i-1] % ((int)pow(10, 9) + 7);
		right[n-i-1] = right[n-i] * v[n-i] % ((int)pow(10, 9) + 7);
	}
	
	long long int prod;
	for (int i = 0; i < n; i++)
	{
		prod = left[i] * right[i] % ((int)pow(10, 9) + 7);
		
		cout << prod << " ";
	}

	return 0;
}