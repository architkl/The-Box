#include <iostream>
#include <vector>
#include <set>
#include <map>

using namespace std;

int distinct(vector <int> A)
{
	vector <int> B;
	int n = A.size(), flag;

	for (int i = 0; i < n; i++)
	{
		flag = 0;
		for (int j = 0; j < B.size(); j++)
		{
			if (A[i] == B[j])
			{
				flag = 1;
				break;
			}
		}

		if (flag == 0)
			B.push_back(A[i]);
	}

	return B.size();
}

int main()
{
	int N;
	cin >> N;

	vector <int> A(N);
	for (int i = 0; i < N; i++)
		cin >> A[i];

	set <int> B;
	map <int, int> cnt;
	int K = distinct(A), l = 0, r = 0;
	long long int sum = 0;
	
	while (l < N)
	{
		while (r < N && B.size() < K)
		{
			B.insert(A[r]);
			cnt[A[r]]++;
			r++;
		}

		if (B.size() == K)
			sum += N - r + 1;

		if (cnt[A[l]] == 1)
			B.erase(A[l]);

		cnt[A[l]]--;
		l++;
	}

	cout << sum << "\n";

	return 0;
}