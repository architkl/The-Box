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

	long long int N, P;
	while (T--)
	{
		cin >> N >> P;

		if (P < N)
		{
			long long int max = 0, cnt = 0;
			for (int i = 1; i <= P; i++)
				if (N % i > max)
					max = N % i;
			
			for (int i = 1; i <= P; i++)
				if (N % i == max)
					cnt++;

			cout << cnt*(P-max)*(P-max) << "\n";

			continue;
		}

		int k = 2;
		while ((P <= N/k || (N % (N/k + 1) == 0)) && (N/k != 0))
			k++;

		if (N/k == 0)
			cout << P * P * P << "\n";

		else /*if (P >= N)*/
			cout << (P-N+N/2+1)*(P-N+N/2+1) + (P-N)*(P-N+N/2+1) + (P-N)*(P-N) << "\n";
	}

	return 0;
}
/*
N/2+1
N-N/2-1
P-N+N/2+1

1 1
1

1 2
8

1 3
27

1 n
n^3

2 1
1

2 2
8

2 3
27

2 4
64

2 n
n^3

3 1
1

3 2
1

3 3
2*2

3 4
3*3 + 1*3 + 1*1

3 5
4*4 + 2*4 + 2*2

3 6
5*5 + 3*5 + 3*3

4 1
1

4 2
8

4 3
2*2

4 4
3*3

4 5
4*4 + 1*4 + 1*1
*/