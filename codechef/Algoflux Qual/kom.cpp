#include<bits/stdc++.h>

using namespace std;

bool mycomp(string i, string j)
{
	return i > j;
}

int main()
{
	int t;
	cin >> t;

	std::cout << std::setprecision(1) << std::fixed;

	string n, temp;
	vector <string> minHeap, maxHeap;
	int i = 0;
	while (i < t)
	{
		cin >> n;

		// if (n == 0)
		// 	continue;
		
		maxHeap.push_back(n);

		cout << double(stoi(maxHeap[0])) << "\n";

		cin >> n;
		i++;
		// while (n == -1)
		// {
		// 	cout << maxHeap[0] << "\n";

		// 	cin >> n;
		// }

		// if (n == 0)
		// 	continue;

		if (n >= maxHeap[0])
			minHeap.push_back(n);

		else
		{
			temp = maxHeap[0];
			maxHeap.pop_back();

			minHeap.push_back(temp);
			maxHeap.push_back(n);
		}

		cout << (double(stoi(maxHeap[0])) + double(stoi(minHeap[0]))) / 2.0 << "\n";

		i++;


		while (i < t)
		{
			cin >> n;
			i++;

			// if (n == -1)
			// {
			// 	cout << maxHeap[0] << "\n";
			// 	continue;
			// }

			if (minHeap.size() == maxHeap.size())
			{
				if (n <= minHeap[0])
				{
					maxHeap.push_back(n);
					push_heap(maxHeap.begin(), maxHeap.end());
				}

				else
				{
					temp = minHeap[0];
					pop_heap(minHeap.begin(), minHeap.end(), mycomp);
					minHeap.pop_back();

					maxHeap.push_back(temp);
					push_heap(maxHeap.begin(), maxHeap.end());

					minHeap.push_back(n);
					push_heap(minHeap.begin(), minHeap.end(), mycomp);
				}

				cout << double(stoi(maxHeap[0])) << "\n";
			}

			else
			{
				if (n >= maxHeap[0])
				{
					minHeap.push_back(n);
					push_heap(minHeap.begin(), minHeap.end(), mycomp);
				}

				else
				{
					temp = maxHeap[0];
					pop_heap(maxHeap.begin(), maxHeap.end());
					maxHeap.pop_back();

					minHeap.push_back(temp);
					push_heap(minHeap.begin(), minHeap.end(), mycomp);	

					maxHeap.push_back(n);
					push_heap(maxHeap.begin(), maxHeap.end());
				}

				cout << (double(stoi(maxHeap[0])) + double(stoi(minHeap[0]))) / 2.0 << "\n";
			}
		}
	}

	return 0;
}