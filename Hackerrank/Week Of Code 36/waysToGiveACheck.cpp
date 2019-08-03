#include <iostream>
#include <vector>

using namespace std;

const int DIM = 8;

void find_king(vector <string> board, int *kx, int *ky)
{
	for (int i = 0; i < DIM; i++)
	{
		for (int j = 0; j < DIM; j++)
		{
			if (board[i][j] == 'k')
			{
				*kx = i;
				*ky = j;
				return;
			}
		}
	}
}

void find_king2(vector <string> board, int *kx, int *ky)
{
	for (int i = 0; i < DIM; i++)
	{
		for (int j = 0; j < DIM; j++)
		{
			if (board[i][j] == 'K')
			{
				*kx = i;
				*ky = j;
				return;
			}
		}
	}
}

int knight(int posx, int posy, int kx, int ky)
{
	if (kx == posx + 1 || kx == posx - 1)
		if (ky == posy - 2 || ky == posy + 2)
			return 1;
	
	if (kx == posx + 2 || kx == posx - 2)
		if (ky == posy - 1 || ky == posy + 1)
			return 1;

	return 0;
}

int rook(vector <string> board, int posx, int posy, int kx, int ky)
{
	if (kx == posx)
	{
		for (int i = min(ky, posy) + 1; i < max(ky, posy); i++)
			if (board[posx][i] != '#')
				return 0;
		return 1;
	}

	if (ky == posy)
	{
		for (int i = min(kx, posx) + 1; i < max(kx, posx); i++)
			if (board[i][posy] != '#')
				return 0;
		return 1;
	}

	return 0;
}

int bishop(vector <string> board, int posx, int posy, int kx, int ky)
{
	if (posx + posy == kx + ky)
	{
		if (posx < kx)
		{
			for (int i = 1; posx + i < kx; i++)
				if (board[posx+i][posy-i] != '#')
					return 0;
			return 1;
		}

		else
		{
			for (int i = 1; posx - i > kx; i--)
				if (board[posx-i][posy+i] != '#')
					return 0;
			return 1;
		}
	}

	if (posy - posx == ky - kx)
	{
		if (posx < kx)
		{
			for (int i = 1; posx + i < kx; i++)
				if (board[posx+i][posy+i] != '#')
					return 0;
			return 1;
		}

		else
		{
			for (int i = 1; posx - i < kx; i++)
				if (board[posx-i][posy-i] != '#')
					return 0;
			return 1;
		}
	}

	return 0;
}
/*
int king(int posx, int posy, int kx, int ky)
{
	if (posx == kx)
		if (abs(posy-ky) == 1)
			return 1;

	if (posy == ky)
		if (abs(posx-kx) == 1)
			return 1;

	if (posx - 1 == kx)
		if (posy - 1 == ky || posy + 1 == ky)
			return 1;

	if (posx + 1 == kx)
		if (posy - 1 == ky || posy + 1 == ky)
			return 1;

	return 0;
}*/

int is_blocking(vector <string> board, int px, int py)
{
	int kx, ky;
	find_king2(board, &kx, &ky);

	board[px][py] = '#';
	board[px-1][py] = 'P';
/*
	for (int i = 0; i < DIM; i++)
	{
		for (int j = 0; j < DIM; j++)
			cout << board[i][j];
		cout << "\n";
	}*/

	for (int i = 0; i < DIM; i++)
	{
		for (int j = 0; j < DIM; j++)
		{
			if (board[i][j] == 'r')
				if (rook(board, i, j, kx, ky))
					return 1;

			if (board[i][j] == 'b')
				if (bishop(board, i, j, kx, ky))
					return 1;
		}
	}

	return 0;

	// for (int i = 0; i < DIM; i++)
	// {
	// 	for (int j = 0; j < DIM; j++)
	// 	{
	// 		if (board[i][j] == 'r')
	// 		{
	// 			if (kx == i)
	// 			{
	// 				for (int l = min(ky, j) + 1; l < max(ky, j); l++)
	// 					if (board[i][l] != '#')
	// 						if (i == px && l == py)
	// 							return 1;
	// 			}

	// 			if (ky == j)
	// 			{
	// 				for (int l = min(kx, i) + 1; l < max(kx, i); l++)
	// 					if (board[l][j] != '#')
	// 						if (l == px && j == py)
	// 							return 1;
	// 			}
	// 		}

	// 		if ()
	// 	}
	// }	
}

int waysToGiveACheck(vector <string> board)
{
	int kx, ky, px, py;
	find_king(board, &kx, &ky);

	int ways = 0;
	for (int i = 0; i < DIM; i++)
	{
		if (board[1][i] == 'P' && board[0][i] == '#')
		{
			if (is_blocking(board, 1, i))
				continue;

			ways += knight(0, i, kx, ky) + rook(board, 0, i, kx, ky) + bishop(board, 0, i, kx, ky)
					+ (rook(board, 0, i, kx, ky) || bishop(board, 0, i, kx, ky));						//queen

			board[1][i] = '#';
			board[0][i] = 'P';

			break;
		}
	}

	for (int i = 0; i < DIM; i++)
	{
		for (int j = 0; j < DIM; j++)
		{
			if (board[i][j] == 'N')
				ways += 4 * knight(i, j, kx, ky);

			else if (board[i][j] == 'R')
				ways += 4 * rook(board, i, j, kx, ky);

			else if (board[i][j] == 'B')
				ways += 4 * bishop(board, i, j, kx, ky);

			else if (board[i][j] == 'Q')
				ways += 4 * (rook(board, i, j, kx, ky) || bishop(board, i, j, kx, ky));
/*
			else if (board[i][j] == 'K')
				ways += 4 * king(i, j, kx, ky);*/
		}
	}

	return ways;
}

int main()
{
	int t;
	cin >> t;

	cin.ignore();

	vector <string> board(DIM);
	//string board[DIM];
	for (int i = 0; i < t; i++)
	{
		for (int j = 0; j < DIM; j++)
			getline(cin, board[j]);

		cout << waysToGiveACheck(board) << "\n";
	}
	return 0;
}