#include <fstream>
#include <algorithm>
#include <string>
#include <vector>
#include <map>

using namespace std;

const string END = "%TEMPLATE-END%";

void init(int W, int H, vector <string> keyboard, map <char, pair <int, int> > &xy)
{
	for (int i = 0; i < H; i++)
	{
		for (int j = 0; j < W; j++)
		{
			xy[keyboard[i][j]] = make_pair(j+1, i+1);
		}
	}
}

int get_cost(map <char, pair <int, int> > xy, vector <string> temp)
{
	int cost = 0, prev_x = 0, prev_y = 0;

	while (prev_y == temp[prev_x].size())
		prev_x++;

	while (temp[prev_x][prev_y] == ' ')
	{
		prev_y++;

		if (prev_y == temp[prev_x].size())
		{
			prev_x++;
			prev_y = 0;
		}
	}

	for (int i = prev_x; i < temp.size(); i++)
	{
		for (int j = 0; j < temp[i].size(); j++)
		{
			if (temp[i][j] == ' ')
				continue;

			cost += max(abs(xy[temp[prev_x][prev_y]].first - xy[temp[i][j]].first),
						abs(xy[temp[prev_x][prev_y]].second - xy[temp[i][j]].second));

			prev_x = i;
			prev_y = j;
		}
	}

	return cost;
}

int main()
{
	ifstream fi("input.txt");
	ofstream fo("output.txt");

	int W, H;
	fi >> W >> H;

	fi.ignore();

	vector <string> keyboard(H);
	for (int i = 0; i < H; i++)
		getline(fi, keyboard[i]);

	string lang[3], t;
	vector <string> temp[3];

	for (int i = 0; i < 3; i++)
	{
		getline(fi, lang[i]);

		getline(fi, t);
		getline(fi, t);

		while (t != END)
		{
			temp[i].push_back(t);
			getline(fi, t);
		}
	}

	fi.close();

	map <char, pair <int, int> > xy;

	init(W, H, keyboard, xy);

	int mn = get_cost(xy, temp[0]), idx = 0, tmp;
	for (int i = 1; i < 3; i++)
	{
		tmp = get_cost(xy, temp[i]);

		if (tmp < mn)
		{
			mn = tmp;
			idx = i;
		}
	}

	fo << lang[idx] << "\n" << mn;

	fo.close();

	return 0;
}