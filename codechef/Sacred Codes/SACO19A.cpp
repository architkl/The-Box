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
#include <string>
#include <math.h>

using namespace std;

#define pb push_back
#define mp make_pair

typedef pair <int, int> pii;
typedef unsigned long long ull;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int T;
	cin >> T;

	int N, Q;
	while (T--)
	{
		cin >> N >> Q;

		vector <vector <string>> teams(N+1, vector <string> (3));
		string info;
		cin.ignore();
		for (int i = 0; i < 3*N; i++)
		{
			getline(cin, info);

			int j = 0;
			string temp = "";
			while (info[j] != ' ')
			{
				temp += info[j];
				j++;
			}

			int t_no = double(stoi(temp));

			j++;
			temp = "";
			while (info[j] != ' ')
			{
				temp += info[j];
				j++;
			}

			string name = temp;
			bool lead = (info[j+1] == 'Y');

			if (lead)
				teams[t_no][0] = name;

			else if (teams[t_no][1] == "")
				teams[t_no][1] = name;
			
			else if (teams[t_no][1] > name)
			{
				temp = teams[t_no][1];
				teams[t_no][1] = name;
				teams[t_no][2] = temp;
			}

			else
				teams[t_no][2] = name;
		}

		int X, Y;
		for (int i = 0; i < Q; i++)
		{
			cin >> X >> Y;

			cout << teams[X][Y-1] << "\n";
		}
	}

	return 0;
}