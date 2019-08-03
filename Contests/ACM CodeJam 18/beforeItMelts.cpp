#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int N_MAX = 100005;

vector <int> token(N_MAX);

int rec(int pos, int s, int ans)
{
	if (s > ans)
		return 0;

	if (s == ans)
		return 1;

	if (pos == -1)
		return 0;

	return max(rec(pos - 1, s + token[pos], ans), rec(pos - 1, s, ans));
}

int main()
{
	int N;
	cin >> N;

	int sum = 0;
	for (int i = 0; i < N; i++)
	{
		cin >> token[i];
		sum += token[i];
	}

	if (sum % 2 || N == 1)
		cout << -1 << "\n";

	else
	{
		int ans = sum / 2;

		if (rec(N-1, 0, ans))
			cout << ans << "\n";

		else
			cout << -1 << "\n";
	}
}