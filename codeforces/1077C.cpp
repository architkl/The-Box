/*
Author: architkl
Language: C++ 11
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
#include <fstream>

using namespace std;

#define pb push_back
#define mp make_pair

typedef pair <int, int> pii;
typedef unsigned long long ull;

int bs(vector <ull> v, ull x)
{
	int low = 0, high = v.size(), mid;

	while (low < high)
	{
		mid = (low + high) / 2;

		if (v[mid] == x)
			return 1;

		else if (v[mid] < x)
			low = mid+1;
		
		else
			high = mid-1;
	}

	return 0;
}

int main()
{
	// ios_base::sync_with_stdio(false);
	// cin.tie(NULL);

	ifstream fi("input.txt");

	int n;
	// cin >> n;
	fi >> n;

	// multiset <int> msa;
	// set <int> sa;
	unordered_map <int, int> freq;
	vector <int> a(n);
	vector <ull> aux(base::sync_with_stdio(false);
	// cin.n);
	ull sum = 0;
	for (int i = 0; i < n; i++)
	{
		// cin >> a[i];
		fi >> a[i];

		// msa.insert(a[i]);
		// sa.insert(a[i]);
		aux[i] = a[i];
		freq[a[i]]++;
		sum += a[i];
	}

	fi.close();

	cout << "HELLO?\n";

	vector <ull> search(n);
	for (int i = 0; i < n; i++)
		search[i] = sum-a[i];

	cout << "SORTING\n";
	sort(aux.begin(), aux.end());
	cout << "SORTED\n";

	vector <int> nice;
	// multiset <int, int>::iterator it;
	// set <int, int>::iterator it;
	for (int i = 0; i < n; i++)
	{
		if (search[i] % 2)
			continue;

		// it = msa.find(search[i]/2);
		// it = sa.find(search[i]/2);

		// if (it == msa.end())
		if (!bs(aux, search[i]/2))
			continue;

		if (search[i]/2 == a[i])
		{
			// it++;

			// if (it == msa.end())
			// 	continue;

			// if (*it == search[i]/2)
			if (freq[a[i]] > 1)
				nice.pb(i);
		}

		else
			nice.pb(i);
	}

	cout << nice.size() << "\n";
	for (auto i : nice)
		cout << i+1 << " ";

	cout << "\n";

	return 0;
}