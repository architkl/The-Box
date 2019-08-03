#include <iostream>
#include <vector>

using namespace std;

bool n_prime[10001] = {};
vector <int> p_vector;

void sieve()
{
	n_prime[0] = n_prime[1] = 1;

	for (int i = 2; i <= 10000; i++)
	{
		if (n_prime[i])
			continue;

		for (int j = 2; i*j <= 10000; j++)
			n_prime[i*j] = 1;
	}
}

void push()
{
	for (int i = 2; i <= 10000; i++)
	{
		if (n_prime[i] == 0)
			p_vector.push_back(i);
	}
}

int ex_or(vector <int> hf, int i, int j)
{
	int temp = 0;

	for (int k = i; k <= j; k++)
		temp ^= hf[k];

	return temp;
}

int main()
{
	int x;
	cin >> x;

	vector <int> hf;

	sieve();
	push();
	
	int num = 1, p_size = p_vector.size(), count = 0, flag;
	for (int i = 561; i <= x; i++)
	{
		flag = 1;
		num = 1;
		count = 0;
		for (int j = 0; j < p_size; j++)
		{
			if (i % p_vector[j] == 0)
			{
				num *= p_vector[j];

				if ((i-1) % (p_vector[j]-1))
				{
					//cout << i-1 << " " << p_vector[j]-1 << "\n";
					flag = 0;
					break;
				}
				count++;
				//cout << i-1 << " " << p_vector[j]-1 << " " << num << "\n";
			}

			if(num == i)
			{
				//cout << num << "\n";
				break;
			}

			if (p_vector[j] > i / 2)
			{
				flag = 0;
				break;
			}
		}

		if (flag && count >= 3)
			hf.push_back(i);
			//cout << i << " ";
	}

	int max = 0, temp = 0, hf_size = hf.size();
	//hf.empty() ? max = 0 : max = hf[0];

	for (int i = 0; i < hf_size; i++)
	{
		for (int j = i; j < hf_size; j++)
		{
			cout << i << " " << j << " ";
			temp = ex_or(hf, i, j);
			cout << temp << "\n";

			if (temp > max)
				max = temp;
		}
		//cout << "temp : " << temp << "\n";
		//cout << "max : " << max << "\n\n";
	}

	cout << max;

	return 0;
}

/*
561 1105 1729 2465 2821 6601 8911
*/