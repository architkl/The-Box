#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

const int V = 100005;
const int rV = 500;

int s[rv+1][rv+1];
int b_arr[V];

void ini()
{
	for (int i = 0; i < V; i++)
		b_arr[i] = 0;

	for (int i = 0; i < rV; i++)
		for (int j = 0; j < rV; j++)
			s[i][j] = 0;
}

int main()
{
	int n;
	cin >> n;

	ini();

	char inp;
	int k, b, q;
	for (int i = 0; i < n; i++)
	{
		cin >> inp;

		if (inp == '+')
		{
			cin >> k >> b;

			b %= k;

			if (k >= rV)
			{
				while (b < V)
				{
					b_arr[b]++;
					b += k;
				}
			}

			else
			{
				s[k][b]++;
			}
		}

		else if (inp == '-')
		{
			cin >> k >> b;

			b %= k;

			if (k >= rV)
			{
				while (b < V)
				{
					b_arr[b]--;
					b += k;
				}
			}

			else
			{
				s[k][b]--;
			}
		}

		else
		{
			cin >> q;

			int ans = b_arr[q];

			for (int i = 1; i < rV; i++)
			{
				ans += s[i][q % i];
			}

			cout << ans << "\n";
		}
	}
	return 0;
}