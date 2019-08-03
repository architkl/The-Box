#include <iostream>
#include <vector>
#include <string>

using namespace std;

bool bead[26];

void ini()
{
	for (int i = 0; i < 26; i++)
		bead[i] = false;
}

int count()
{
	int c = 0;
	for (int i = 0; i < 26; i++)
		c += bead[i];

	return c;
}

int main()
{
	int N, K;
	cin >> N >> K;

	int M, cnt = 27, index, temp;
	vector <string> S(N);
	for (int i = 0; i < N; i++)
	{
		cin >> M;

		cin.ignore();
		getline(cin, S[i]);

		ini();
		for (int j = 0; j < M; j++)
		{
			if (bead[S[i][j] - 65])
				continue;

			bead[S[i][j] - 65] = true;
		}

		temp = count();
		if (temp < cnt)
		{
			cnt = temp;
			index = i;
		}

		else if (temp == cnt)
		{
			if (S[i] < S[index])
				index = i;
		}
	}

	cout << S[index];

	return 0;
}