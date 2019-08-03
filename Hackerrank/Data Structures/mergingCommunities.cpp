/*
Author: architkl
Language: C++ 11
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <math.h>

using namespace std;

#define pb push_back
#define mp make_pair

typedef pair <int, int> pii;
typedef unsigned long long ull;

const int N_MAX = 1e5 + 5;

int parent[N_MAX];
int children[N_MAX];
int dsu_rank[N_MAX];

void init()
{
    for (int i = 0; i < N_MAX; i++)
    {
        parent[i] = i;
        children[i] = 0;
        dsu_rank[i] = 0;
    }
}

int find_parent(int x)
{
    if (parent[x] != x)
        parent[x] = find_parent(parent[x]);

    return parent[x];
}

void dsu_union(int x, int y)
{
    int px = find_parent(x), py = find_parent(y);

    if (px == py)
        return;

    if (dsu_rank[px] > dsu_rank[py])
    {
        parent[py] = px;
        children[px] += children[py] + 1;
    }

    else
    {
        parent[px] = py;
        children[py] += children[px] + 1;
    }

    if (dsu_rank[px] == dsu_rank[py])
        dsu_rank[py]++;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    init();
    
    int N, Q;
    cin >> N >> Q;

    char query;
    int I, J;
    //cin.ignore();

    for (int i = 0; i < Q; i++)
    {
        cin >> query;

        if (query == 'M')
        {
            cin >> I >> J;
            dsu_union(I, J);
        }
        
        else
        {
            cin >> I;
            cout << children[find_parent(I)] + 1 << "\n";
        }
    }
    
    return 0;
}