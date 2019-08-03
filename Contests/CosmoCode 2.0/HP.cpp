#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <math.h>

using namespace std;

pair <int, int> P0;

void swap(pair<int, int> &a, pair <int, int> &b)
{
	pair <int, int> c = a;
	a = b;
	b = c;
}

int orientation(pair <int, int> p, pair <int, int> q, pair <int, int> r)
{
	int o = (q.second - p.second) * (r.first - q.first) - (q.first - p.first) * (r.second - q.second);

	if (o == 0)
		return 0;	//collinear

	return o > 0 ? 1 : 2;
}

int sq_dist(pair <int, int> a, pair <int, int> b)
{
	return (pow((a.first - b.first), 2) + pow((a.second - b.second), 2));
}

bool compare(pair <int, int> a, pair <int, int> b)
{
	int o = orientation(P0, a, b);

	if (o == 0)
		return (sq_dist(P0, a) < sq_dist(P0, b)) ? 0 : 1;
	
	return (o == 2) ? 0 : 1;
}

pair <int, int> next(stack < pair <int, int> > &s)
{
	pair <int, int> p = s.top();
	s.pop();

	pair <int, int> res = s.top();
	s.push(p);

	return res;
}

double area(int X[], int Y[], int n)
{
	double A = 0;
	int j = n - 1;
	for (int i = 0; i < n; i++)
	{
		A += (X[j] + X[i]) * (Y[j] - Y[i]);
		j = i;
	}

	return abs(A / 2);
}

void convex_hull(vector < pair <int, int> > P)
{
	int n = P.size(), ymin = P[0].second, y_idx = 0;
	for (int i = 1; i < n; i++)
	{
		if ( (P[i].second < ymin) || (P[i].second == ymin && P[i].first < P[y_idx].first))
		{
			ymin = P[i].second;
			y_idx = i;
		}
	}

	swap(P[0], P[y_idx]);
	P0 = P[0];

	cout << "START\n";
	sort(P.begin() + 1, P.end(), compare);
	cout << "STOP\n";

	for (int i = 0; i < n; i++)
		cout << P[i].first << " " << P[i].second << "\n";

	cout << "\n";

	vector < pair <int, int> > fpoints;
	fpoints.push_back(P[0]);
	for (int i = 1; i < n; i++)
	{
		while (i < n-1 && orientation(P0, P[i], P[i+1]) == 0)
			i++;

		fpoints.push_back(P[i]);
	}
	cout << "WUT\n";

	for (int i = 0; i < fpoints.size(); i++)
		cout << fpoints[i].first << " " << fpoints[i].second << "\n";

	cout << "\n";	

	stack < pair <int, int> > S;
	S.push(fpoints[0]);
	S.push(fpoints[1]);
	S.push(fpoints[2]);

	for (int i = 3; i < fpoints.size(); i++)
	{
		//cout << fpoints[i].first << " " << fpoints[i].second << "\n";
		while (orientation(next(S), S.top(), fpoints[i]) != 2)
		{
			//cout << S.top().first << " " << S.top().second << "\n";
			S.pop();
		}
		//cout << "\n";

		S.push(fpoints[i]);
	}

	int sz = S.size();
	int X[sz], Y[sz];
	for (int i = 0; i < sz; i++)
	{
		X[i] = S.top().first;
		Y[i] = S.top().second;

		cout << X[i] << " " << Y[i] << "\n";

		S.pop();
	}
}

int main()
{
	int n;
	cin >> n;

	vector < pair <int, int> > P(3*n);
	int x, y;
	for (int i = 0; i < 3*n; i++)
	{
		cin >> x >> y;

		P[i] = make_pair(x, y);
	}
	
	convex_hull(P);
	
	return 0;
}