#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int N, Q;
	cin >> N;

	cin.ignore();
	string S[N];
	for (int i = 0; i < N; i++)
		getline(cin, S[i]);

	cin >> Q;
	cin.ignore();
	string P[Q];
	for (int i = 0; i < Q; i++)
		getline(cin, P[i]);

	int count;
	for (int i = 0; i < Q; i++)
	{
		count = 0;
		for (int j = 0; j < N; j++)
		{
			if (P[i] == S[j])
				count++;
		}
		cout << count << "\n";
	}

	return 0;
}