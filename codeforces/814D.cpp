/*
Author: architkl
Language: C++ 14
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <unordered_map>
#include <queue>
#include <set>
#include <climits>
#include <iomanip>
#include <string>
#include <cmath>

using namespace std;

#define pb push_back
#define mp make_pair
#define pi 3.14159265358979323846

typedef pair <int, int> pii;
typedef pair <int, pii> piii;
typedef unsigned long long ull;

const int N_MAX = 1005;

int parent[N_MAX];

void init()
{
	for (int i = 0; i < N_MAX; i++)
		parent[i] = i;
}

bool comp(piii a, piii b)
{
	return a.first > b.first;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	init();

	int n;
	cin >> n;

	vector <piii> circle(n);
	int x, y, r;
	for (int i = 0; i < n; i++)
	{
		cin >> x >> y >> r;

		circle[i] = mp(r, mp(x, y));
	}

	// Sort in desc according to radius
	
	sort(circle.begin(), circle.end(), comp);

	vector <int> parity(n, -1);
	long long int p_x, p_y, p_r, s_x, s_y, s_r, temp;
	for (int i = 0; i < n; i++)
	{
		p_x = circle[i].second.first;
		p_y = circle[i].second.second;
		p_r = circle[i].first;

		for (int j = i+1; j < n; j++)
		{
			s_x = circle[j].second.first;
			s_y = circle[j].second.second;
			s_r = circle[j].first;

			// Check if circle j is inside circle i

			temp = s_x*s_x + s_y*s_y + 2 * (-p_x) * s_x + 2 * (-p_y) * s_y + p_x*p_x + p_y*p_y - p_r*p_r;
			if (temp < 0)
			{
				// Assigning parity accoring to level
				// As circles are sorted the last assigned parent is the one directly containing it

				parent[j] = i;
				parity[j] = (parity[i] == -1) ? 1 : !parity[i];
			}
		}
	}

	double area = 0;

	// Separate out the root from others to maximize area (greedy)

	for (int i = 0; i < n; i++)
		area += pow(circle[i].first, 2) * pow(-1, (parity[i] == -1 || parity[i]) ? 0 : 1);

	area *= pi;

	cout << setprecision(9) << fixed << area << "\n";

	return 0;
}

/*
x2 + y2 + 2gx + 2fy + c = 0
c = g2 + f2 - r2
*/