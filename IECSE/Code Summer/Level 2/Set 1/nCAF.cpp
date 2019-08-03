#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>

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

	int freq_sum = 0;
	long long int exp_len = 0;
	for (int i = 0; i < T-1; i++)
	{
		exp_len += (i+1) * V[i].second;
		freq_sum += V[i].second;
	}

	freq_sum += V[T-1].second;
	exp_len += (T-1) * V[T-1].second;

	cout << setprecision(8) << fixed << double(exp_len) / freq_sum << "\n";

	return 0;
}