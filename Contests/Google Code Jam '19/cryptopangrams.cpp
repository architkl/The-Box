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
#include <iomanip>
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

	int t, case_ = 0;
	cin >> t;

	int N, L;
	while (t--)
	{
		case_++;

		cin >> N >> L;

		vector <int> vec(L);
		for (int i = 0; i < L; i++)
			cin >> vec[i];

		vector <int> text;
		int x;
		for (int i = 1; i < L; i++)
		{
			if (vec[i] == vec[i-1])
			{
				int j = i;
				while (vec[j] == vec[j-1] && j < L)
					j++;

				if (j == L)
				{
					int r = vec[i-2] / text.back();
					int q = vec[i-1] / r;

					while (i <= L)
					{
						text.pb(r);
						text.pb(q);
						i += 2;
					}

					if (i == L+1)
						text.pb(r);
				}

				x = __gcd(vec[j-1], vec[j]);

				int p = x, q = vec[j-1] / x;
				stack <int> S;

				while (j > 0)
				{
					S.push(p);
					S.push(q);
					j -= 2;
				}

				if (j == 0)
					S.push(p);

				// ab ba ab ba ac cd dc cd dc
				// a  b  a  b  a  c  d  c  d  c

				while (S.size() != 1)
				{
					text.pb(S.top());
					S.pop();
				}

				i = j;
			}

			else
			{
				x = __gcd(vec[i-1], vec[i]);
				text.pb(vec[i-1] / x);
			}
		}

		if (vec[L-1] != vec[L-2])
		{
			text.pb(x);
			text.pb(vec.back() / x);
		}

		set <int> primes;

		for (auto i : text)
			primes.insert(i);

		map <int, char> hash;
		char c = 'A';

		for (auto i : primes)
		{
			hash[i] = c;
			c++;
		}

		cout << "Case #" << case_ << ": ";
		for (auto i : text)
			cout << hash[i];

		cout << "\n";
	}

	return 0;
}
/*
A B C D
217 123 321
*/