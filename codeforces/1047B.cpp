#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool mycompx(pair <int, int> a, pair <int, int> b)
{
	if (a.first < b.first)
		return 1;

	else if (a.first == b.first)
		return a.second < b.second;

	return 0;
}

bool mycompy(pair <int, int> a, pair <int, int> b)
{
	if (a.second < b.second)
		return 1;

	else if (a.second == b.second)
		return a.first < b.first;

	return 0;
}

bool mycomp(pair <int, int> a, pair <int, int> b)
{
	return (a.first + a.second < b.first + b.second);
}

int main()
{
	int n;
	cin >> n;

	vector < pair <int, int> > p(n);
	int x, y;
	for (int i = 0; i < n; i++)
	{
		cin >> x >> y;

		p[i] = make_pair(x, y);
	}

	sort(p.begin(), p.end(), mycomp);
	
	cout << p[p.size()-1].first + p[p.size()-1].second << "\n";

	return 0;
}