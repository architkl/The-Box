#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool comp(pair <char, int> p1, pair <char, int> p2)
{
	if (p1.second == p2.second)
		return (p1.first < p2.first);

	return (p1.second < p2.second);
}

int main()
{
	int T;
	cin >> T;

	vector < pair <char, int> > V;
	int n;
	char c;
	for (int i = 0; i < T; i++)
	{
		cin >> c >> n;

		V.push_back(make_pair(c, n));
	}

	sort(V.begin(), V.end(), comp);

	return 0;
}