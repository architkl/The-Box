#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <math.h>

using namespace std;

struct Point
{
	int x, y;
};

Point P0;
vector <Point> fpoints;

void swap(Point &a, Point &b)
{
	Point c = a;
	a = b;
	b = c;
}

int orientation(Point p, Point q, Point r)
{
	int o = (q.y - p.y) * (r.x - q.x) - (q.x - p.x) * (r.y - q.y);

	if (o == 0)
		return 0;	//collinear

	return o > 0 ? 1 : 2;
}

long long int sq_dist(Point a, Point b)
{
	long long int dx = a.x - b.x, dy = a.y - b.y;

	return (dx * dx + dy * dy);
}

bool compare(Point a, Point b)
{
	int o = orientation(P0, a, b);

	if (o == 0)
		return (sq_dist(P0, a) < sq_dist(P0, b)) ? 1 : 0;
	
	return (o == 2) ? 1 : 0;
}

Point next(stack <Point> s)
{
	Point p = s.top();
	s.pop();

	Point res = s.top();
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

void convex_hull(Point P[], int n)
{
	int ymin = P[0].y, y_idx = 0;
	for (int i = 1; i < n; i++)
	{
		if ( (P[i].y < ymin) || (P[i].y == ymin && P[i].x < P[y_idx].x))
		{
			ymin = P[i].y;
			y_idx = i;
		}
	}

	swap(P[0], P[y_idx]);
	P0 = P[0];

	sort(P + 1, P + n, compare);
	/*for (int i = 0; i < n; i++)
		cout << P[i].x << " " << P[i].y << "\n";*/

	fpoints.push_back(P[0]);
	for (int i = 1; i < n; i++)
	{
		while (i < n-1 && orientation(P0, P[i], P[i+1]) == 0)
			i++;

		fpoints.push_back(P[i]);
	}

	stack <Point> S;
	S.push(fpoints[0]);
	S.push(fpoints[1]);
	S.push(fpoints[2]);

	for (int i = 3; i < fpoints.size(); i++)
	{
		while (orientation(next(S), S.top(), fpoints[i]) != 2)
			S.pop();

		S.push(fpoints[i]);
	}

	int sz = S.size();
	int X[sz], Y[sz];
	for (int i = 0; i < sz; i++)
	{
		X[i] = S.top().x;
		Y[i] = S.top().y;

		cout << X[i] << " " << Y[i] << "\n";

		S.pop();
	}

	cout << area(X, Y, sz) << "\n";
}

int main()
{
	int n;
	cin >> n;

	Point P[3*n];
	int x, y;
	for (int i = 0; i < 3*n; i++)
	{
		cin >> x >> y;

		P[i].x = x;
		P[i].y = y;
	}
	
	convex_hull(P, 3*n);
	
	return 0;
}