#include <iostream>

using namespace std;

const int N_MAX = 100005;
const int K = 1000000000;

class Heap
{
	int H[N_MAX];
	int N;
	public:
		Heap()
		{
			for (int i = 0; i < N_MAX; i++)
				H[i] = 0;

			N = 0;
		}
		void swap(int a, int b);
		void maxHeapify(int idx);
		void insert(int x);
		void printMax();
		void popMax();
};

void Heap::swap(int a, int b)
{
	int temp = H[a];
	H[a] = H[b];
	H[b] = temp;
}

void Heap::maxHeapify(int idx)
{
	int leftChild = 2 * idx, rightChild = 2 * idx + 1, largest = idx;

	if (leftChild <= N && H[leftChild] > H[largest])
		largest = leftChild;

	if (rightChild <= N && H[rightChild] > H[largest])
		largest = rightChild;

	if (largest != idx)
	{
		swap(idx, largest);
		maxHeapify(largest);
	}
}

void Heap::insert(int x)
{
	H[++N] = x;

	if (N > 1)
	{
		int parent = N / 2, child = N;

		while (H[child] > H[parent] && parent > 0)
		{
			swap(child, parent);
			child = parent;
			parent /= 2;
		}
	}
}

void Heap::printMax()
{
	N == 0 ? cout << "Heap is empty!\n" : cout << H[1] << "\n";
}

void Heap::popMax()
{
	if (N == 0)
	{
		cout << "Heap is empty!\n";
		return;
	}

	if (N > 1)
	{
		swap(1, N);
		N--;
		maxHeapify(1);
	}

	else
		N--;
}

int main()
{
	int t;
	cin >> t;

	int q;
	while (t--)
	{
		cin >> q;

		Heap h;

		int op, x;
		while (q--)
		{
			cin >> op;

			if (op == 1)
			{
				cin >> x;

				h.insert(x);
			}

			else if (op == 2)
			{
				h.printMax();
			}

			else if (op == 3)
			{
				h.popMax();
			}
		}
	}

	return 0;
}