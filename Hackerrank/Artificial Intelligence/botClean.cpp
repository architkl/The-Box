#include<iostream>
#include<vector>

using namespace std;

void find_close(vector <string> board, int d[2], int bx, int by)
{
    int dist[5][5];
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            dist[i][j] = 100;
            if (board[i][j] == 'd')
                dist[i][j] = abs(bx-i) + abs(by-j);
        }
    }

    int m = dist[0][0];
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            if (dist[i][j] < m)
            {
                m = dist[i][j];
                d[0] = i;
                d[1] = j;
            }
        }
    }
}

void next_move(int posr, int posc, vector <string> board)
{
    if (posr == 5)
        return;

    if (posc == 5)
        next_move(posr + 1, 0, board);

    if (board[posr][posc] == 'd')
    {
        cout << "CLEAN\n";
        return;
    }

    int d[2];
    find_close(board, d, posr, posc);

    if (posr != d[0])
        posr < d[0] ? cout << "DOWN\n" : cout << "UP\n";

    else
        posc < d[1] ? cout << "RIGHT\n" : cout << "LEFT\n";
}

int main()
{
    int pos[2];
    
    vector <string> board;
    cin>>pos[0]>>pos[1];
    
    for(int i=0;i<5;i++)
    {
        string s;cin >> s;
        board.push_back(s);
    }
    
    next_move(pos[0], pos[1], board);

    return 0;
}