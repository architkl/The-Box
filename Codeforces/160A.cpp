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
#include <bitset>
#include <iomanip>
#include <climits>
#include <string>
#include <math.h>

using namespace std;

#define pb push_back
#define mp make_pair

typedef pair <int, int> pii;
typedef pair <int, pii> piii;
typedef unsigned long long ull;
typedef long long ll;

const int N_MAX = 105;

int arr[N_MAX];

void swap(int &a, int &b)
{
	int c = a;
	a = b;
	b = c;
}

int partition(int start, int end)
{
	int p = start, val = arr[end];
	for (int i = start; i < end; i++)
	{
		if (arr[i] < val)
		{
			swap(arr[i], arr[p]);
			p++;
		}
	}

	swap(arr[p], arr[end]);
	return p;
}

void quicksort(int start, int end)
{
	if (start < end)
	{
		int pos = partition(start, end);
		quicksort(start, pos-1);
		quicksort(pos+1, end);
	}
}

void merge(int start, int mid, int end)
{
	int temp[end-start+1], i = start, j = mid+1, k = 0;

	while (i <= mid && j <= end)
	{
		if (arr[i] > arr[j])
			temp[k++] = arr[i++];
		
		else
			temp[k++] = arr[j++];
	}

	while (i <= mid)
		temp[k++] = arr[i++];

	while (j <= end)
		temp[k++] = arr[j++];

	for (int p = 0; p <= end-start; p++)
		arr[start+p] = temp[p];
}

void m_sort(int start, int end)
{
	if (start < end)
	{
		int mid = (start + end) / 2;
		m_sort(start, mid);
		m_sort(mid+1, end);
		merge(start, mid, end);
	}
}

int main()
{
	int n;
	cin >> n;

	int sum = 0;
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];

		sum += arr[i];
	}

	// quicksort(0, n-1);
	m_sort(0, n-1);

	int temp = 0;
	/*for (int i = n-1; i >= 0; i--)
	{
		temp += arr[i];

		if (2*temp > sum)
		{
			cout << n-i << "\n";
			break;
		}
	}*/

	for (int i = 0; i < n; i++)
	{
		temp += arr[i];

		if (2*temp > sum)
		{
			cout << i+1 << "\n";
			break;
		}
	}

	return 0;
}