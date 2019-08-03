#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	int N, D;
	cin >> N >> D;

	vector < pair <int, int> > A;
	int p, q;
	for (int i = 0; i < N; i++)
	{
		cin >> p >> q;
		A.push_back(make_pair(p, q));
	}

	sort(A.begin(), A.end());

	int i = 0, j = 1;
	long long int sum = A[i].second, temp = A[i].second;
	while (i < j && j < N)
	{
		if (A[j].first - A[i].first <= D)
		{
			temp += A[j].second;
			j++;
		}
		
		else
		{
			temp -= A[i].second;
			i++;
		}

		if (temp > sum)
			sum = temp;
	}

	cout << sum << "\n";

	return 0;
}