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
#include <iomanip>
#include <climits>
#include <string>
#include <math.h>

using namespace std;

#define pb push_back
#define mp make_pair

typedef pair <int, int> pii;
typedef unsigned long long ull;
/*
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int t, case_ = 0;
	cin >> t;

	int n;
	string path;

	while (t--)
	{
		case_++;

		cin >> n >> path;

		map <pii, pii> exc;
		pii cur = mp(0, 0);

		for (int i = 0; i < path.length(); i++)
		{
			if (path[i] == 'S')
			{
				exc.insert(mp(cur, mp(cur.first+1, cur.second)));
				cur.first += 1;
			}
			
			else
			{
				exc.insert(mp(cur, mp(cur.first, cur.second+1)));
				cur.second += 1;
			}
		}

		queue < pair <pii, string> > myQ;
		myQ.push(mp(mp(0, 0), ""));

		pair <pii, string> cur2;
		int cur_x, cur_y;

		while (!myQ.empty())
		{
			cur2 = myQ.front();
			myQ.pop();

			cur_x = cur2.first.first;
			cur_y = cur2.first.second;

			if (cur_x == n-1 && cur_y == n-1)
			{
				cout << "Case #" << case_ << ": " << cur2.second << "\n";
				break;
			}

			if (cur_x + 1 < n && exc[cur2.first] != mp(cur_x+1, cur_y))
				myQ.push(mp(mp(cur_x+1, cur_y), cur2.second + "S"));

			if (cur_y + 1 < n && exc[cur2.first] != mp(cur_x, cur_y+1))
				myQ.push(mp(mp(cur_x, cur_y+1), cur2.second + "E"));
		}
	}

	return 0;
}

int main()
{
	int t, case_ = 0;
	cin >> t;

	int n;
	string path;

	while (t--)
	{
		case_++;

		cin >> n >> path;

		map <int, int> exc;
		int cur = 0;

		for (int i = 0; i < path.length(); i++)
		{
			if (path[i] == 'S')
			{
				// exc.insert(mp(cur, cur + n));
				exc[cur] = cur + n;
				// cout << cur/n << ", " << cur%n << ": " << exc[cur] << "\n";
				cur += n;
			}
			
			else
			{
				// exc.insert(mp(cur, cur + 1));
				exc[cur] = (cur + 1);
				// cout << cur/n << ", " << cur%n << ": " << exc[cur] << "\n";
				cur += 1;
			}

			// cout << cur << ": " << exc[cur] << "\n";
		}

		queue < pair <int, string> > myQ;
		myQ.push(mp(0, ""));

		pair <int, string> cur2;

		while (!myQ.empty())
		{
			cur2 = myQ.front();
			myQ.pop();

			// cout << cur2.first/n << ", " << cur2.first%n << ": " << exc[cur2.first] << "\n";

			if (cur2.first == n*n - 1)
			{
				cout << "Case #" << case_ << ": " << cur2.second << "\n";
				break;
			}

			if (cur2.first+n < n*n && exc[cur2.first] != cur2.first+n)
				myQ.push(mp(cur2.first + n, cur2.second + "S"));

			if ((cur2.first+1) % n != 0 && exc[cur2.first] != (cur2.first+1))
				myQ.push(mp(cur2.first + 1, cur2.second + "E"));
		}
	}

	return 0;
}

map <int, int> exc;

string dfs(int x, int n)
{
	if (x == n*n - 1)
		return "Y";

	if (x+n < n*n && exc[x] != x+n)
	{
		string str = dfs(x+n, n);
		// cout << str << "\n";
		if (str[0] != 'N')
			return ("S"+str);
	}

	if ((x+1)%n != 0 && exc[x] != x+1)
	{
		string str = dfs(x+1, n);
		// cout << str << "\n";
		if (str[0] != 'N')
			return ("E"+str);
	}

	return "N";
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int t, case_ = 0;
	cin >> t;

	int n;
	string path;

	while (t--)
	{
		case_++;

		cin >> n >> path;

		int cur = 0;
		exc.clear();

		for (int i = 0; i < path.length(); i++)
		{
			if (path[i] == 'S')
			{
				exc[cur] = cur + n;
				cur += n;
			}
			
			else
			{
				exc[cur] = (cur + 1);
				cur += 1;
			}
		}

		string str = dfs(0, n);
		cout << "Case #" << case_ << ": ";

		for (int i = 0; i < str.length()-1; i++)
			cout << str[i];

		cout << "\n";

		// for (int i = str.length()-1; i>= 0; i++)
		// 	cout << str[i];
	}

	return 0;
}*/

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int t, case_ = 0;
	cin >> t;

	int n;
	string path;

	while (t--)
	{
		case_++;

		cin >> n >> path;

		cout << "Case #" << case_ << ": ";

		for (int i = 0; i < path.length(); i++)
		{
			if (path[i] == 'S')
				cout << "E";

			else
				cout << "S";
		}

		cout << "\n";
	}

	return 0;
}