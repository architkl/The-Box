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

#include <fstream>

using namespace std;

#define pb push_back
#define mp make_pair

typedef pair <int, int> pii;
typedef unsigned long long ull;
typedef long long ll;

struct trieNode
{
	unordered_map <char, trieNode*> children;
	int cnt = 0;
	bool endOfWord;

	trieNode()
	{
		endOfWord = false;
	}
};

void insertNode(trieNode *root, string s)
{
	trieNode *cur = root;

	for (int i = 0; i < s.length(); i++)
	{
		trieNode *node = cur->children[s[i]];

		if (node == NULL)
		{
			node = new trieNode();
			cur->children[s[i]] = node;
		}

		cur->cnt++;
		cur = cur->children[s[i]];
	}

	cur->endOfWord = true;
}

int searchNode(trieNode *root, string s)
{
	trieNode *cur = root;

	for (int i = 0; i < s.length(); i++)
	{
		if (cur->children[s[i]] == NULL)
			return false;

		cur = cur->children[s[i]];
	}

	return (cur->cnt + cur->endOfWord);
}

int main()
{
	ifstream fi("input02.txt");

	int n;
	// cin >> n;
	fi >> n;

	string s, t;
	trieNode *root = new trieNode();

	while (n--)
	{
		// cin >> s >> t;
		fi >> s >> t;

		if (s == "add")
			insertNode(root, t);

		else
			cout << searchNode(root, t) << "\n";
	}

	fi.close();

	return 0;
}