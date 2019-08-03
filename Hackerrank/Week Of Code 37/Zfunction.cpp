#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>

using namespace std;

const int n_MAX = 55;
const int INF = 1000;
const int K = pow(10, 9) + 7;

string alphabet = "abcdefghijklmnopqrstuvwxyz1234567890!@#$%^&*()_+-=";

int Z[n_MAX];
long long int Z_values[n_MAX] = {};

//vector <int> Z_values;

void ini()
{
	for (int i = 0; i < n_MAX; i++)
		Z[i] = INF;
}

void createZ(string s)
{
	int l = 0, r = 0, n = s.length();

	for (int i = 1; i < n; i++)
	{
		//cout << i << " ";
		if (i > r)
		{
			l = r = i;

			while (r < n && s[r-l] == s[r])
				r++;

			Z[i] = r - l;
			//cout << Z[i] << "\n";
			r--;
		}

		else
		{
			int k = i - l;

			if (Z[k] < r - i + 1)
				Z[i] = Z[k];

			else
			{
				l = r = i;

				while (r < n && s[r-l] == s[r])
					r++;

				Z[i] = r - l;
				//cout << Z[i] << " ";
				r--;
			}
		}
	}
}

void get_string(string str, int pos, int n, int k)
{
	if (pos == n)
	{
		ini();
		createZ(str);

		int t = *max_element(Z + 1, Z + n);
		//cout << t << " " << Z_values[t] << " ";
		Z_values[t]++;
		//cout << Z_values[t] << " " << K << " ";
		Z_values[t] %= K;
		//cout << Z_values[t] << "\n";

		return;
	}

	for (int i = 0; i < k; i++)
	{
		str += alphabet[i];
		get_string(str, pos + 1, n, k);
		str.pop_back();
	}
}

int main()
{
	int n, k;
	cin >> n >> k;

	/*createZ("aaa");
	for (int i = 1; i < 3; i++)
		cout << Z[i] << " ";*/

	get_string("", 0, n, k);

	long long int sum = 0;

	for (int i = 1; i < n_MAX; i++)
	{
		//cout << Z_values[i] << "\n";
		Z_values[i] *= i;
		Z_values[i] %= K;

		sum += Z_values[i];
		sum %= K;
	}

	cout << sum << "\n";

	return 0;
}