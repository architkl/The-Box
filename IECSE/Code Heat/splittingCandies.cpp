#include <iostream>

using namespace std;

void swap(int &a, int &b)
{
	int c = a;
	a = b;
	b = a;
}

long long int ans(long long int a, long long int b, long long int c1, long long int c2)
{
	long long int q, cur = c1, end, r, temp = c1;

	while(temp / a != 0)
	{
		cur += temp / a;
		temp /= a;
	}

	if (cur % a == 0)
		cur++;

	end = cur + c2;

	cout << cur << " " << end << " ";

	q = cur / a;

	if (a != b)
	{
		end = end - q;
		temp = end - cur + cur % b;

		while (temp / b != 0)
		{
			temp += end % b;
			end += temp / b;
			temp /= b;
		}

		while (q / b != 0)
		{
			end += q / b;
			q /= b;
		}
	}

	else
	{
		temp = c2 + cur % b;
		while (temp / b != 0)
		{
			temp += end % b;
			end += temp / b;
			temp /= b;
		}
	}

	cout << end << " ";

	//r = end / b - cur / b;

	cout << end << "\n";

	//long long int final = end + r;

	return max(end, cur);
}


int main()
{
	int T;
	cin >> T;

	long long int c1, c2, a, b;
	for (int i = 0; i < T; i++)
	{
		cin >> c1 >> c2 >> a >> b;

		cout << min(ans(a, b, c1, c2), ans(b, a, c2, c1)) << "\n";
	}

	return 0;
}