#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	int T;
	cin >> T;

	long long int n, m;
	for (int i = 0; i < T; i++)
	{
		cin >> n >> m;

		vector <long long int> Heap;
		Heap.push_back(n);

		long long int gap;
		for (int j = 1; j < m; j++)
		{
			gap = Heap.front();
			gap--;
			
			pop_heap(Heap.begin(), Heap.end());
			Heap.pop_back();
			
			Heap.push_back(gap/2);
			push_heap(Heap.begin(), Heap.end());
			
			Heap.push_back(gap - gap/2);
			push_heap(Heap.begin(), Heap.end());
		}

		if (Heap.front() % 2)
			cout << Heap.front() / 2 << " " << Heap.front() / 2 << "\n";

		else
		{
			Heap.front()--;
			cout << max(Heap.front() / 2, Heap.front() - Heap.front() / 2) << " "
				 << min(Heap.front() / 2, Heap.front() - Heap.front() / 2) << "\n";
		}
	}

	return 0;
}