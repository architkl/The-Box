#include <iostream>
#include <vector>

using namespace std;

const int K = 1e9 + 7;

long long int bin_mod(long long int a, long long int b)
{
	if (b == 0)
		return 1;

	long long int res = bin_mod(a, b/2);
	res *= res;
	res %= K;

	if (b % 2)
	{
		res *= a;
		res %= K;
	}

	return res;
}

int main()
{
	string N;
	cin >> N;

	int A;
	cin >> A;
	
	vector <int> V;
	for (int i = 0; i < N.length(); i++)
	{
		if (N[i] == '0' || N[i] == '5')
		{
			V.push_back(i);
			//cout << V[V.size()-1] << " ";
		}
	}
	//cout << "\n";
				

	long long int ans = 0, temp, r = bin_mod(2, N.length());
	int mod_inv = bin_mod(r - 1, K - 2);

	for (int i = 0; i < V.size(); i++)
	{
	    temp = bin_mod(2, V[i]);
		temp %= K;

		temp = temp * (bin_mod(r, A) - 1);
		temp %= K;
		temp *= mod_inv;
		temp %= K;
		//cout << temp << " ";
		
		ans += temp;
		ans %= K;
	}

	cout << ans << "\n";

	return 0;
}