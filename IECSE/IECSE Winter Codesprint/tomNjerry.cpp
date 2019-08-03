#include <iostream>
#include <algorithm>

using namespace std;

void i_sort(int a[], int b[], int n)
{
	int i = 0, j, t1, t2;
	for (; i < n-1; i++)
	{
		j = i + 1;
		t1 = a[j];
		t2 = b[j];
		while (t1 < a[j-1] && j > 0)
		{
			a[j] = a[j-1];
			b[j] = b[j-1];
			j--;
		}
		
		if (t1 == a[j-1])
		{
			while ((t2 > b[j-1] && t1 == a[j-1]) && j > 0)
			{
				a[j] = a[j-1];
				b[j] = b[j-1];
				j--;		
			}
		}
		a[j] = t1;
		b[j] = t2;
	}
}

int height(int a[], int b[], int sum, int cur, int prev, int n)
{
	if (cur == n)
		return sum;

	if (b[cur] > b[prev] && a[cur] > a[prev])
		return max(height(a, b, sum + b[cur], cur + 1, cur, n),
					height(a, b, sum, cur + 1, prev, n));
	
	return max(height(a, b, sum, cur + 1, prev, n),
				height(a, b, b[cur], cur + 1, cur, n));
}

int main()
{
	int n;
	cin >> n;

	int R[n], H[n];
	for (int i = 0; i < n; i++)
		cin >> R[i] >> H[i];

	i_sort(R, H, n);

	cout << height(R, H, H[0], 1, 0, n);

	return 0;
}