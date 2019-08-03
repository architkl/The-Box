#include <iostream>
#include <vector>

using namespace std;

void displayPathtoPrincess(int n, vector <string> grid)
{
    int px, py, mx, my;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (grid[i][j] == 'p')
            {
                px = i;
                py = j;
            }
            
            else if (grid[i][j] == 'm')
            {
                mx = i;
                my = j;
            }
        }
    }

    //cout << px << " " << py << "\n" << mx << " " << my << "\n";

    while (px - mx > 0)
    {
        cout << "DOWN\n";
        mx++;
    }

    while (px - mx < 0)
    {
        cout <<"UP\n";
        mx--;
    }

    while (py - my > 0)
    {
        cout << "RIGHT\n";
        my++;
    }

    while (py - my < 0)
    {
        cout << "LEFT\n";
        my--;
    }
}

int main()
{
    int m;
    vector <string> grid;

    cin >> m;

    for(int i=0; i<m; i++) {
        string s; cin >> s;
        grid.push_back(s);
    }

    displayPathtoPrincess(m,grid);

    return 0;
}