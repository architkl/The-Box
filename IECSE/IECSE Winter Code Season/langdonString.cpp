#include <iostream>
#include <string>
//#include <map>

using namespace std;

const string board = "qwertyuiopasdfghjkl;zxcvbnm,./";

/*
map <char, int> board;
const int LAST = 29;

void init()
{
	board['q'] = 0;
	board['w'] = 1;
	board['e'] = 2;
	board['r'] = 3;
	board['t'] = 4;
	board['y'] = 5;
	board['u'] = 6;
	board['i'] = 7;
	board['o'] = 8;
	board['p'] = 9;
	board['a'] = 10;
	board['s'] = 11;
	board['d'] = 12;
	board['f'] = 13;
	board['g'] = 14;
	board['h'] = 15;
	board['j'] = 16;
	board['k'] = 17;
	board['l'] = 18;
	board[';'] = 19;
	board['z'] = 20;
	board['x'] = 21;
	board['c'] = 22;
	board['v'] = 23;
	board['b'] = 24;
	board['n'] = 25;
	board['m'] = 26;
	board[','] = 27;
	board['.'] = 28;
	board['/'] = 29;
}*/

int main()
{
	char ch;
	cin >> ch;
	cin.ignore();

	string str, str2 = "";
	getline(cin, str);

	int move, len = str.length();
	ch == 'L' ? move = 1 : move = -1;

	for (int i = 0; i < len; i++)
	{
		//cout << (signed)board.find(str[i]) + move << "\n";
		if ((signed)board.find(str[i]) + move < 0)
			str2 += '/';

		else if (board.find(str[i]) + move > 29)
			str2 += 'q';

		else
			str2 += board[board.find(str[i]) + move];
	}

	cout << str2;

	return 0;
}