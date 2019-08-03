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
typedef long long ll;

bool isVowel(char c)
{
	if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')
		return true;

	return false;
}

int cnt_vowel(string s)
{
	int cnt = 0;
	for (auto i : s)
		if (isVowel(i))
			cnt++;

	return cnt;
}

char last_vowel(string s)
{
	for (int i = s.length()-1; i >= 0; i--)
		if (isVowel(s[i]))
			return s[i];
}

int main()
{
	/*ios_base::sync_with_stdio(false);
	cin.tie(NULL);*/

	int n;
	cin >> n;

	unordered_map <int, unordered_map <char, vector<string>>> ds;
	string s;
	int first_idx, sec_idx;
	for (int i = 0; i < n; i++)
	{
		cin >> s;

		ds[cnt_vowel(s)][last_vowel(s)].pb(s);
	}

	vector <pair <string, string>> sec_word;
	vector <vector <string>> first_word;
	for (auto i : ds)
	{
		// cout << "\n\n" << i.first << "\n";
		// cout << "a:\n";
		first_word.pb(vector <string> ());

		vector <string>::iterator it;
		for (it = i.second['a'].begin(); it != i.second['a'].end(); it += 2)
		{
			if (it+1 == i.second['a'].end())
				break;

			sec_word.pb(mp(*(it), *(it+1)));
		}

		if (i.second['a'].size() % 2)
			first_word.back().pb(i.second['a'].back());

		// cout << "\ne:\n";
		for (it = i.second['e'].begin(); it != i.second['e'].end(); it += 2)
		{
			if (it+1 == i.second['e'].end())
				break;

			sec_word.pb(mp(*(it), *(it+1)));
		}

		if (i.second['e'].size() % 2)
			first_word.back().pb(i.second['e'].back());

		// cout << "\ni:\n";
		for (it = i.second['i'].begin(); it != i.second['i'].end(); it += 2)
		{
			if (it+1 == i.second['i'].end())
				break;

			sec_word.pb(mp(*(it), *(it+1)));
		}

		if (i.second['i'].size() % 2)
			first_word.back().pb(i.second['i'].back());

		// cout << "\no:\n";
		for (it = i.second['o'].begin(); it != i.second['o'].end(); it += 2)
		{
			if (it+1 == i.second['o'].end())
				break;

			sec_word.pb(mp(*(it), *(it+1)));
		}

		if (i.second['o'].size() % 2)
			first_word.back().pb(i.second['o'].back());

		// cout << "\nu:\n";
		for (it = i.second['u'].begin(); it != i.second['u'].end(); it += 2)
		{
			if (it+1 == i.second['u'].end())
				break;

			sec_word.pb(mp(*(it), *(it+1)));
		}

		if (i.second['u'].size() % 2)
			first_word.back().pb(i.second['u'].back());
	}

	/*cout << "Second Words: ";
	for (auto i : sec_word)
		cout << "(" << i.first << ", " << i.second << ") ";

	cout << "\nFirst Words:\n";
	for (auto i : first_word)
	{
		if (i.size() == 0)
			continue;

		for (auto j : i)
			cout << j << " ";
		cout << "\n";
	}*/

	int itr = 0;
	vector < pair < pair <string, string>, pair <string, string> > > ans;
	for (int i = 0; i < first_word.size(); i++)
	{
		if (first_word[i].size() <= 1)
			continue;

		if (itr == sec_word.size())
			break;

		for (int j = 0; j+1 < first_word[i].size(); j += 2)
		{
			ans.pb(mp(mp(first_word[i][j], sec_word[itr].first), mp(first_word[i][j+1], sec_word[itr].second)));
			// cout << first_word[i][j] << " " << sec_word[itr].first << "\n" << first_word[i][j+1] << " " << sec_word[itr].second << "\n";
			itr++;

			if (itr == sec_word.size())
				break;
		}
	}

	for (; itr+1 < sec_word.size(); itr += 2)
	{
		ans.pb(mp(mp(sec_word[itr+1].first, sec_word[itr].first), mp(sec_word[itr+1].second, sec_word[itr].second)));
		// cout << sec_word[itr+1].first << " " << sec_word[itr].first << "\n" << sec_word[itr+1].second << " " << sec_word[itr].second << "\n";
	}

	cout << ans.size() << "\n";
	for (auto i : ans)
		cout << i.first.first << " " << i.first.second << "\n" << i.second.first << " " << i.second.second << "\n";

	return 0;
}