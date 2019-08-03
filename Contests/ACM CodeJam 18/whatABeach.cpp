#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool mycomp(pair <int, int> p1, pair <int, int> p2)
{
	return (p1.first > p2.first);
}

int main()
{
	int T, R, F;
	cin >> T >> R >> F;

	vector <int> S(T), N(T);

	for (int i = 0; i < T; i++)
		cin >> S[i];

	for (int i = 0; i < T; i++)
		cin >> N[i];

	vector < pair <int, int> > SN;
	for (int i = 0; i < T; i++)
		SN.push_back(make_pair(S[i], N[i]));

	sort(SN.begin(), SN.end(), mycomp);

	/*for (int i = 0; i < T; i++)
		cout << SN[i].first << " " << SN[i].second << "\n"*/

	long long int S_val = 0;
	for (int i = 0; i < T; i++)
		S_val += S[i] * N[i];

	S_val /= (R + F);

	int shells = 0;
	for (int i = 0; S_val > 0 && i < T; i++)
	{
		shells += S_val / SN[i].first;

		S_val %= SN[i].first;
	}

	cout << shells << "\n";

	return 0;
}