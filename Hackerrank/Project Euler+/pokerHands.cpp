/*
Author: architkl
Language: C++ 14
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <unordered_map>
#include <stack>
#include <queue>
#include <set>
#include <bitset>
#include <iomanip>
#include <climits>
#include <string>
#include <math.h>

using namespace std;

#define pb push_back
#define mp make_pair

typedef pair <int, int> pii;
typedef unsigned long long ull;

unordered_map <char, int> card_rank;

void init()
{
	for (char i = '2'; i <= '9'; i++)
		card_rank[i] = i-48;

	card_rank['T'] = 10;
	card_rank['J'] = 11;
	card_rank['Q'] = 12;
	card_rank['K'] = 13;
	card_rank['A'] = 15;
}

bool mycomp(string a, string b)
{
	if (a[1] == b[1])
		return (a[0] < b[0]);
	
	return (a[1] < b[1]);
}

int highCard(vector <string> hand)
{
	int mx = 0;
	for (auto i : hand)
		if (card_rank[i[0]] > mx)
			mx = card_rank[i[0]];

	return mx;
}

void delHigh(vector <string> &hand)
{
	int mx = highCard(hand);
	for (int i = 0; i < hand.size(); i++)
	{
		if (card_rank[hand[i][0]] == mx)
		{
			hand.erase(hand.begin() + i);
			return;
		}
	}
}

int onePair(vector <string> hand)
{
	unordered_map <char, int> freq;

	for (auto i : hand)
		freq[i[0]]++;

	for (auto i : freq)
		if (i.second == 2)
			return card_rank[i.first];

	return -1;
}

int twoPairs(vector <string> hand)
{
	unordered_map <char, int> freq;

	for (auto i : hand)
		freq[i[0]]++;

	int mx = -1, cnt = 0;
	for (auto i : freq)
	{
		if (i.second == 2)
		{
			cnt++;
			if (card_rank[i.first] > mx)
				mx = card_rank[i.first];
		}
	}

	return (cnt == 2) ? mx : -1;
}

int threeOfAKind(vector <string> hand)
{
	unordered_map <char, int> freq;

	for (auto i : hand)
		freq[i[0]]++;

	for (auto i : freq)
		if (i.second == 3)
			return card_rank[i.first];

	return -1;
}

bool straight(vector <string> hand)
{
	unordered_map <char, bool> mark;
	for (auto i : hand)
		mark[i[0]] = true;

	bool f;
	char str[14] = {'A', '2', '3', '4', '5', '6', '7', '8', '9', 'T', 'J', 'Q', 'K', 'A'};
	for (int i = 0; i < 10; i++)
	{
		f = 1;
		for (int j = 0; j < hand.size(); j++)
		{
			if (!mark[str[i+j]])
			{
				f = 0;
				break;
			}
		}

		if (f)
			return true;
	}

	return false;
}

bool flush(vector <string> hand)
{
	char suit = hand[0][1];
	for (auto i : hand)
		if (i[1] != suit)
			return false;

	return true;
}

int fullHouse(vector <string> hand)
{
	if (threeOfAKind(hand) == -1)
		return -1;

	unordered_map <char, int> freq;
	for (auto i : hand)
		freq[i[0]]++;

	bool f = 0;
	for (auto i : freq)
	{
		if (i.second == 2)
		{
			f = 1;
			break;
		}
	}

	if (!f)
		return -1;

	return threeOfAKind(hand);
}

int fourOfAKind(vector <string> hand)
{
	unordered_map <char, int> freq;

	for (auto i : hand)
		freq[i[0]]++;

	for (auto i : freq)
		if (i.second == 4)
			return card_rank[i.first];

	return -1;
}

bool straightFlush(vector <string> hand)
{
	if (straight(hand) && flush(hand))
		return true;

	return false;
}
/*
bool royalFLush(vector <string> hand)
{
	if (!flush(hand))
		return false;

	bool f;
	char royal[5] = {'T', 'J', 'Q', 'K', 'A'};
	for (int i = 0; i < 5; i++)
	{
		f = 0;
		for (auto j : hand)
		{
			if (j[0] == royal[i])
			{
				f = 1;
				break;
			}
		}

		if (!f)
			return false;
	}

	return true;
}*/

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	init();

	int T;
	cin >> T;

	vector < vector <string> > cards(2, vector <string> (5));
	while (T--)
	{
		for (int i = 0; i < 2; i++)
			for (int j = 0; j < 5; j++)
				cin >> cards[i][j];

		// sort(cards[0].begin(), cards[0].end(), mycomp);
		// sort(cards[1].begin(), cards[1].end(), mycomp);

		if (straightFlush(cards[0]) || straightFlush(cards[1]))
		{
			if (straightFlush(cards[0]) && straightFlush(cards[1]))
			{
				vector <string> p1 = cards[0];
				int p1High = highCard(p1);
				delHigh(p1);

				if (p1High == 15)
				{
					if (highCard(p1) == 13)
						cout << "Player 1\n";

					else
						cout << "Player 2\n";
				}

				else if (highCard(cards[0]) > highCard(cards[1]))
					cout << "Player 1\n";

				else
					cout << "Player 2\n";
			}

			else if (straightFlush(cards[0]))
				cout << "Player 1\n";

			else
				cout << "Player 2\n";

			cout << "Straight Flush\n";
		}

		else if (fourOfAKind(cards[0]) != -1 || fourOfAKind(cards[1]) != -1)
		{
			if (fourOfAKind(cards[0]) == fourOfAKind(cards[1]))
			{
				int kicker[2], score = fourOfAKind(cards[0]);
				for (int i = 0; i < 2; i++)
				{
					for (auto j : cards[i])
					{
						if (card_rank[j[0]] != score)
						{
							kicker[i] = card_rank[j[0]];
							break;
						}
					}
				}

				if (kicker[0] > kicker[1])
					cout << "Player 1\n";

				else
					cout << "Player 2\n";
			}

			else if (fourOfAKind(cards[0]) > fourOfAKind(cards[1]))
				cout << "Player 1\n";

			else
				cout << "Player 2\n";

			cout << "Four Of A Kind\n";
		}

		else if (fullHouse(cards[0]) != -1 || fullHouse(cards[1]) != -1)
		{
			if (fullHouse(cards[0]) == fullHouse(cards[1]))
			{
				int pair[2], score = fullHouse(cards[0]);
				for (int i = 0; i < 2; i++)
				{
					for (auto j : cards[i])
					{
						if (card_rank[j[0]] != score)
						{
							pair[i] = card_rank[j[0]];
							break;
						}
					}
				}

				if (pair[0] > pair[1])
					cout << "Player 1\n";

				else
					cout << "Player 2\n";
			}

			else if (fullHouse(cards[0]) > fullHouse(cards[1]))
				cout << "Player 1\n";

			else
				cout << "Player 2\n";

			cout << "Full House\n";
		}

		else if (flush(cards[0]) || flush(cards[1]))
		{
			if (flush(cards[0]) && flush(cards[1]))
			{
				vector <string> p1 = cards[0], p2 = cards[1];
				while (highCard(p1) == highCard(p2) && p1.size() != 1)
				{
					delHigh(p1);
					delHigh(p2);
				}

				if (highCard(p1) > highCard(p2))
					cout << "Player 1\n";

				else
					cout << "Player 2\n";
			}

			else if (flush(cards[0]))
				cout << "Player 1\n";

			else
				cout << "Player 2\n";

			cout << "Flush\n";
		}

		else if (straight(cards[0]) || straight(cards[1]))
		{
			if (straight(cards[0]) && straight(cards[1]))
			{
				vector <string> p1 = cards[0];
				int p1High = highCard(cards[0]);
				delHigh(p1);

				if (p1High == 15)
				{
					if (highCard(p1) == 13)
						cout << "Player 1\n";

					else
						cout << "Player 2\n";
				}

				else if (highCard(cards[0]) > highCard(cards[1]))
					cout << "Player 1\n";

				else
					cout << "Player 2\n";
			}

			else if (straight(cards[0]))
				cout << "Player 1\n";

			else
				cout << "Player 2\n";

			cout << "Straight\n";
		}

		else if (threeOfAKind(cards[0]) != -1 || threeOfAKind(cards[1]) != -1)
		{
			if (threeOfAKind(cards[0]) == threeOfAKind(cards[1]))
			{
				vector <string> kickers[2];
				int score = threeOfAKind(cards[0]);
				for (int i = 0; i < 2; i++)
					for (auto j : cards[i])
						if (card_rank[j[0]] != score)
							kickers[i].pb(j);
				
				if (highCard(kickers[0]) == highCard(kickers[1]))
				{
					delHigh(kickers[0]);
					delHigh(kickers[1]);

					if (highCard(kickers[0]) > highCard(kickers[1]))
						cout << "Player 1\n";

					else
						cout << "Player 2\n";
				}

				else if (highCard(kickers[0]) > highCard(kickers[1]))
					cout << "Player 1\n";

				else
					cout << "Player 2\n";
			}

			else if (threeOfAKind(cards[0]) > threeOfAKind(cards[1]))
				cout << "Player 1\n";

			else
				cout << "Player 2\n";

			cout << "Three Of A Kind\n";
		}

		else if (twoPairs(cards[0]) != -1 || twoPairs(cards[1]) != -1)
		{
			if (twoPairs(cards[0]) == twoPairs(cards[1]))
			{
				vector <string> p[2];
				int score = twoPairs(cards[0]);
				for (int i = 0; i < 2; i++)
					for (auto j : cards[i])
						if (card_rank[j[0]] != score)
							p[i].pb(j);

				if (onePair(p[0]) == onePair(p[1]))
				{
					int score = onePair(p[0]), kicker[2];
					for (int i = 0; i < 2; i++)
					{
						for (auto j : p[i])
						{
							if (card_rank[j[0]] != score)
							{
								kicker[i] = card_rank[j[0]];
								break;
							}
						}
					}

					if (kicker[0] > kicker[1])
						cout << "Player 1\n";

					else
						cout << "Player 2\n";
				}

				else if (onePair(p[0]) > onePair(p[1]))
					cout << "Player 1\n";

				else
					cout << "Player 2\n";
			}

			else if (twoPairs(cards[0]) > twoPairs(cards[1]))
				cout << "Player 1\n";

			else
				cout << "Player 2\n";

			cout << "Two Pairs\n";
		}

		else if (onePair(cards[0]) != -1 || onePair(cards[1]) != -1)
		{
			if (onePair(cards[0]) == onePair(cards[1]))
			{
				vector <string> p[2];
				int score = onePair(cards[0]);
				for (int i = 0; i < 2; i++)
					for (auto j : cards[i])
						if (card_rank[j[0]] != score)
							p[i].pb(j);

				while (highCard(p[0]) == highCard(p[1]) && p[0].size() != 1)
				{
					delHigh(p[0]);
					delHigh(p[1]);
				}

				if (highCard(p[0]) > highCard(p[1]))
					cout << "Player 1\n";

				else
					cout << "Player 2\n";
			}

			else if (onePair(cards[0]) > onePair(cards[1]))
				cout << "Player 1\n";

			else
				cout << "Player 2\n";

			cout << "One Pair\n";
		}

		else
		{
			vector <string> p1 = cards[0], p2 = cards[1];
			while (highCard(p1) == highCard(p2) && p1.size() != 1)
			{
				delHigh(p1);
				delHigh(p2);
			}

			if (highCard(p1) > highCard(p2))
				cout << "Player 1\n";

			else
				cout << "Player 2\n";

			cout << "High Card\n";
		}
	}

	return 0;
}