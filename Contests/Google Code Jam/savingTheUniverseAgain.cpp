#include <iostream>
#include <math.h>

using namespace std;

int check_possible(int D, string S)
{
	int n = S.length(), damage = 0, multiplier = 1, count_S = 0;
	for (int i = 0; i < n; i++)
	{
		if (S[i] == 'C')
			multiplier *= 2;

		else
		{
			damage += multiplier;
			count_S++;
		}
	}
																	//SCSSCC
	if (count_S > D)
		return -1;

	if (damage <= D)
		return 1;

	else
		return 0;
}

void swap(string &S)
{
	char c;
	for (int i = S.length() - 1; i >= 0; i--)
	{
		if (S[i] == 'S' && S[i-1] == 'C')
		{
			c = S[i];
			S[i] = S[i-1];
			S[i-1] = c;
			return;
		}
	}
}

int main()
{
	int T;
	cin >> T;

	string S;
	int D, cnt, ans;
	for (int i = 0; i < T; i++)
	{
		cin >> D >> S;

		ans = check_possible(D, S);
		cnt = 0;

		if (ans == -1)
			cout << "Case #" << i + 1 << ": " << "IMPOSSIBLE\n";

		else if (ans == 1)
			cout << "Case #" << i + 1 << ": " << cnt << "\n";

		else
		{
			while (ans == 0)
			{
				swap(S);
				cnt++;
				ans = check_possible(D, S);
			}

			cout << "Case #" << i + 1 << ": " << cnt << "\n";
		}
	}

	return 0;
}