/*
Author: architkl
Language: C++ 14
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <unordered_map>
#include <queue>
#include <set>
#include <climits>
#include <string>
#include <math.h>

using namespace std;

#define pb push_back
#define mp make_pair

typedef pair <int, int> pii;
typedef unsigned long long ull;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int T;
	cin >> T;

	cin.ignore();

	string S, t, r;
	while (T--)
	{
		getline(cin, S);

		t = r = "";

		t += S[0];
		t += S[1];
		t += S[2];
		t += S[3];

		r += S[S.length()-4];
		r += S[S.length()-3];
		r += S[S.length()-2];
		r += S[S.length()-1];

		if (t == "not ")
			cout << "Real Fancy\n";

		else if (r == " not")
			cout << "Real Fancy\n";

		else if (S.find(" not ") == -1)
			cout << "regularly fancy\n";

		else
			cout << "Real Fancy\n";

		cout << t << " " << r << "\n";
	}

	return 0;
}