#include <iostream>
#include <vector>

using namespace std;

int max_money(int arr[], int n, int match, int con, int money)
{
	if (match == n)
		return money;

	if (con == 2)
		return max_money(arr, n, match + 1, 0, money);

	if (con == 1)
		return max(max_money(arr, n, match + 1, 2, money + arr[match]),
					max_money(arr, n, match + 1, 0, money));

	return max_money(v, match + 1, 1, money + arr[match]);
}

int main()
{
	int N;
	cin >> N;

	int arr[N];
	for (int i = 0; i < N; i++)
		cin >> arr[i];

	cout << max(max_money(arr, N, 1, 1, arr[0]), max_money(arr, N, 1, 0, 0));

	return 0;
}