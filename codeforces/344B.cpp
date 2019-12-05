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

int main()
{
	int a, b, c;
	cin >> a >> b >> c;
	
	if (a+b-c < 0 || a-b+c < 0 || -a+b+c < 0 || (a+b-c)/2.0 != (a+b-c)/2)
		cout << "Impossible\n";

	else
		cout << (a+b-c)/2 << " " << (-a+b+c)/2 << " " << (a-b+c)/2 << "\n";

	return 0;
}
