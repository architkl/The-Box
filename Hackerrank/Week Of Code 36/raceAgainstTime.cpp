#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void print(vector <int> v)
{
	for (int i = 0; i < v.size(); i++)
	{
		cout << v[i] << " ";
	}
	cout << "\n";
}

void print(vector <long long int> v)
{
	for (int i = 0; i < v.size(); i++)
	{
		cout << v[i] << " ";
	}
	cout << "\n";
}

int main()
{
	int N, h;
	cin >> N >> h;

	vector <int> H(N-1), P(N-1);
	for (int i = 0; i < N-1; i++)
		cin >> H[i];
	for (int i = 0; i < N-1; i++)
		cin >> P[i];

	vector <long long int> sum;
	vector <int> height;

	sum.push_back(0);
	height.push_back(h);

	for (int i = 0; i < N-1; i++)
	{
		int initial_size = height.size();
		for (int j = 0; j < initial_size; j++)
		{
			if (height[j] < H[i])
			{
				sum[j] += H[i] - height[j] + P[i];
				height[j] = H[i];
			}

			else if (height[j] == H[i] && P[i] < 0)
				sum[j] += P[i];

			else if (height[j] > H[i])
			{
				if (P[i] < 0)
				{
					height.push_back(H[i]);
					sum.push_back(sum[j] + height[j] - H[i] + P[i] + 1);
				}
			}

			sum[j] += 1;
		}

		//print(height);
		//print(sum);

		for (int j = 0; j < height.size(); j++)
		{
			for (int k = j + 1; k < height.size(); k++)
			{
				if (height[j] == height[k])
				{
					if (sum[j] < sum[k])
					{
						height.erase(height.begin()+k);
						sum.erase(sum.begin()+k);
						k--;
					}
					
					else
					{
						height.erase(height.begin()+j);
						sum.erase(sum.begin()+j);
						j--;
						break;
					}
				}
			}

			//cout << height[j] << " " << sum[j] << "\n";
		}

		//print(height);
		//print(sum);
	}

	cout << *min_element(sum.begin(), sum.end()) + 1 << "\n";

	return 0;
}

/*
2
1 5 3
-3 0 2

5
2 6 2
2 3 2

0 0 min(8, 2) 1
min(16, 8) 10 2 1
8 10 2 1

e e e 1
e e 5 1

(4, 5)

e e 2 1

(3, 2)

e 10 2 1

(3, 2) (2, 12)

16 10 2 1
8 10 2 1
*/