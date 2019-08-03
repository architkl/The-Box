#include <iostream>
#include <vector>
#include <stack>
using namespace std;

#define pb push_back
#define mp make_pair

typedef pair <int, int> pii;
typedef unsigned long long ull;

bool vis[50][50];

void init()
{
    for (int i = 0; i < 50; i++)
        for (int j = 0; j < 50; j++)
            vis[i][j] = false;
}

bool check(int x, int y)
{
    if (x < 0 || x >= n || y < 0 || y >= n || vis[x][y])
        return false;

    return true;
}

void dfs( int r, int c, int pacman_r, int pacman_c, int food_r, int food_c, vector <string> grid){
    stack <pii> S;
    S.push(mp(pacman_r, pacman_c));

    pii cur;
    bool f = false;

    while (1)
    {
        cur = S.top();
        vis[cur.first][cur.second] = true;

        if (grid[cur.first][cur.second] == '.')
            break;

        if (check(cur.first-1, cur.second))
        {
            S.push(mp(cur.first-1, cur.second));
            continue;
        }

        if (check(cur.first, cur.second-1))
        {
            S.push(mp(cur.first, cur.second-1));
            continue;
        }

        if (check(cur.first, cur.second+1))
        {
            S.push(mp(cur.first, cur.second+1));
            continue;
        }

        if (check(cur.first+1, cur.second))
        {
            S.push(mp(cur.first+1, cur.second));
            continue;
        }

        S.pop();
    }
}

int main(void) {

    int r,c, pacman_r, pacman_c, food_r, food_c;
    
    cin >> pacman_r >> pacman_c;
    cin >> food_r >> food_c;
    cin >> r >> c;
    
    vector <string> grid;

    for(int i=0; i<r; i++) {
        string s; cin >> s;
        grid.push_back(s);
    }

    dfs( r, c, pacman_r, pacman_c, food_r, food_c, grid);

    return 0;
}