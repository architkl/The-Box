#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

void swap(int &a, int &b, int &a_i, int &b_i)
{
	int c = a;
	a = b;
	b = c;

	c = a_i;
	a_i = b_i;
	b_i = c;
}
/*
int search(vector <int> v, int n, int start)
{
	vector <int>::iterator it = v.begin() + start;
	for (; it != v.end(); it++)
	{
		if (*it == n)
			return (it - v.begin());
	}
	return -1;
}

void print(vector <int> v)
{
	vector <int>::iterator it;
	for (it = v.begin(); it != v.end(); it++)
	{
		cout << *it << " ";
	}
	cout << "\n";
}
*/
int main()
{
	ifstream fi("/home/archit/Desktop/C++/Test");

	int n, k;
	fi >> n >> k;
	//cin >> n >> k;

	int t, index[n+1];
	vector <int> v;
	for (int i = 0; i < n; i++)
	{
		fi >> t;
		//cin >> t;
		v.push_back(t);
		index[t] = i;
	}

	fi.close();

	if (k > n)
		k = n;

	int count = 0;
	for (int i = 0; (count < k) && (i < n-1); i++)
	{
		if (v[i] != n-i)
		{
			swap(v[i], v[index[n-i]], index[v[i]] ,index[n-i]);
			//print(v);
			count++;
		}
	}

	vector <int>::iterator it;
	for (it = v.begin(); it != v.end(); it++)
	{
		cout << *it << " ";
	}

	return 0;
}