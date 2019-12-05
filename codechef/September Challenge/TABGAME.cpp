#include <iostream>

using namespace std;

int main()
{
	int T;
	cin >> T;

	string  N, M, ans;
	int Q, x, y;
	for (int i = 0; i < T; i++)
	{
		cin >> M >> N >> Q;

		ans = "";

		for (int j = 0; j < Q; j++)
		{
			cin >> x >> y;

			ans += char(calc(x, y, M, N) + 48);
		}

		cout << ans << "\n";
	}

	return 0;
}