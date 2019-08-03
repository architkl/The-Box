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

struct trieNode
{
	unordered_map <char, trieNode*> children;
	bool endOfWord;

	trieNode()
	{
		endOfWord = false;
	}
};

bool insertNode(trieNode *root, string s)
{
	bool f = 0;
	trieNode *cur = root;

	for (int i = 0; i < s.length(); i++)
	{
		trieNode *node = cur->children[s[i]];

		if (node == NULL)
		{
			node = new trieNode;
			cur->children[s[i]] = node;
		}

		if (cur->endOfWord)
			f = 1;
		
		cur = cur->children[s[i]];
	}

	if (cur->endOfWord || cur->children.size() != 0)
		f = 1;

	cur->endOfWord = true;

	return f;
}

bool searchNode(trieNode *root, string s)
{
	trieNode *cur = root;

	for (int i = 0; i < s.length(); i++)
	{
		if (cur->children[s[i]] == NULL)
			return false;

		cur = cur->children[s[i]];
	}

	return cur->endOfWord;
}

int main()
{
	trieNode *root = new trieNode();

	int n;
	cin >> n;

	string s;
	bool f = 0;
	string temp = "";
	while (n--)
	{
		cin >> s;

		f = insertNode(root, s);

		if (temp.length() == 0 && f)
			temp = s;
	}

	if (temp.length() != 0)
		cout << "BAD SET\n" << temp << "\n";

	else
		cout << "GOOD SET\n";

	return 0;
}