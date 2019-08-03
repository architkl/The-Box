#include <iostream>
#include <queue>
#include <vector>

using namespace std;

const int K = 1e9 + 7;

int main()
{
	int N, M, X;
	cin >> N >> M >> X;

	priority_queue <int, vector <int>, greater <int>> pq;
	int price;
	for (int i = 0; i < N; i++)
	{
		cin >> price;

		pq.push(price);
	}

	long long int sum = 0;
	for (int i = 0; i < M; i++)
	{
		price = pq.top();
		sum += price;

		pq.pop();
		pq.push((price ^ X) + 1);
	}

	cout << sum % K << "\n";

	return 0;
}