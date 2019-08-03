#include <iostream>
#include <set>
#include <unordered_map>
#include <algorithm>
#include <vector>

using namespace std;

bool comp(int i, int j)
{
	return (i > j);
}

int main()
{
	int Q;
	cin >> Q;

	vector <int> heap;
	unordered_map <int, int> freq;
	int op, v;
	while (Q--)
	{
		cin >> op;

		if (op == 1)
		{
			cin >> v;

			heap.push_back(v);
			push_heap(heap.begin(), heap.end(), comp);
			freq[v] = 1;
		}

		else if (op == 2)
		{
			cin >> v;

			freq[v]--;
		}

		else
		{
			while (freq[heap.front()] == 0)
			{
				pop_heap(heap.begin(), heap.end(), comp);
				heap.pop_back();
			}

			cout << heap.front() << "\n";
		}
	}

	return 0;
}