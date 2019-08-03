#include <iostream>
#include <vector>

using namespace std;

void nextMove(int n, int r, int c, vector <string> grid)
{
	int px, py, f = 0;
    for (int i = 0; i < n; i++)
    {
    	for (int j = 0; j < n; j++)
    	{
    		if (grid[i][j] == 'p')
    		{
    			px = i;
    			py = j;
    			f = 1;
    			break;
    		}
    	}
    	if (f)
    		break;
    }

    if (py != c)
    	py < c ? cout << "LEFT\n" : cout << "RIGHT\n";

    else
    	px < r ? cout << "UP\n" : cout << "DOWN\n";
}

int main(void)
{
    int n, r, c;
    vector <string> grid;

    cin >> n;
    cin >> r;
    cin >> c;

    for(int i=0; i<n; i++)
    {
        string s; cin >> s;
        grid.push_back(s);
    }

    nextMove(n, r, c, grid);
    return 0;
}