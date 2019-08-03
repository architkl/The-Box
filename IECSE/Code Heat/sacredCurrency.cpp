#include <iostream>
#include <vector>

using namespace std;

const int K = 1e9 + 7;

int G[2000], P[1000];

long long int find_seq(int cg, int cp, int prev, int size_g, int size_p)
{
	if (cp == size_p)
		return 1;

	if (cg == size_g)
		return 0;

	long long int ans = 0;
	for (int i = cg; i < size_g; i++)
	{
		if (G[i] + P[cp] >= prev)
			ans += find_seq(i+1, cp+1, G[i] + P[cp], size_g, size_p);
	}

	return ans;
}

int main()
{
	int g, p;
	cin >> g >> p;

	for (int i = 0; i < g; i++)
		cin >> G[i];

	for (int i = 0; i < p; i++)
		cin >> P[i];

	cout << find_seq(0, 0, 0, g, p) % K << "\n";

	return 0;
}