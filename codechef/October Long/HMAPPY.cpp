/*
Author: architkl
Language: C++ 11
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <math.h>

using namespace std;

#define push_back pb
//#define make_pair mp

typedef pair <int, int> pii;
typedef unsigned long long ull;

bool mycomp(pii a, pii b)
{
	return (a.first < b.first);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int N, M;
	cin >> N >> M;

	vector <int> A(N), B(N);
	int t;
	for (int i = 0; i < N; i++)
		cin >> A[i];

	for (int i = 0; i < N; i++)
		cin >> B[i];

	priority_queue <pii, vector < pii >, bool(*)(pii, pii)> pq(mycomp);
	for (int i = 0; i < N; i++)
		pq.push(make_pair(A[i] * B[i], i));

	pii temp;
	for (int i = 0; i < M; i++)
	{
		temp = pq.top();
		pq.pop();

		temp.first -= B[temp.second];

		pq.push(temp);
	}

	for (int i = 0; i < N; i++)
	{
		cout << pq.top().first << " ";
		pq.pop();
	}

	return 0;
}