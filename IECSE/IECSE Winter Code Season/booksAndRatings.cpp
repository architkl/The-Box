#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int N;
	cin >> N;

	vector <int> A(N), v;
	long long int sum = 0;
	for (int i = 0; i < N; i++)
	{
		cin >> A[i];

		if (A[i] > 0)
		{
			sum += A[i];
			v.push_back(i);
		}
	}

	if (v.size() == 0)
		cout << -1;

	else
	{
		cout << sum << "\n";
		int n = v.size();
		for (int i = 0; i < n; i++)
			cout << v[i] << " ";
	}

	return 0;
}