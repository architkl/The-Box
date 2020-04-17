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
#include <unordered_set>
#include <bitset>
#include <iomanip>
#include <climits>
#include <string>
#include <cstring>
#include <cmath>

using namespace std;

#define pb push_back
#define mp make_pair

typedef pair <int, int> pii;
typedef pair <int, pii> piii;
typedef unsigned long long ull;
typedef long long ll;

map <int, int> factors;

void factorize(int n)
{
	factors[1]++;

	int t1 = sqrt(n), t2 = n;
	for (int i = 2; i <=  t1; i++)
	{
		while (n % i == 0)
		{
			factors[i]++;
			n /= i;
		}

		while (n % (t2/i) == 0)
		{
			factors[t2/i]++;
			n /= (t2/i);
		}
	}
}

int main() {
	int n;
	cin >> n;

	cout << n << " ";

	// map <int, int>::iterator it;
	int temp = n, sum, lim = sqrt(n);
	while (1) {
		sum = 1;
		lim = sqrt(temp);

		// factors.clear();
		// factorize(temp);

		// for (it = factors.begin(); it != factors.end(); it++) {
		// 	// cout << it->first << " " << it->second << "\n";
		// 	sum += (it->first)*(it->second);
		// }

		for (int i = 2; i <= lim; i++) {
			if (temp % i == 0) {
				sum += i;

				if (i != temp/i) sum += (temp / i);
			}
		}

		if (sum == n) break;

		cout << sum << " ";

		temp = sum;

		if (temp == 1) {
			cout << 0;
			break;
		}
	}

	cout << "\n";

	return 0;
}
/*
16 - 1, 2, 4, 8
15 - 1, 3, 5
9 - 1, 3
4 - 1, 2
3 - 1
*/
