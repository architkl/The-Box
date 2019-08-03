#include <iostream>

using namespace std;

const int K = 1000000000;

struct node
{
	int n;
	node *next;
};

class queue
{
	node *front, *rear;
	public:
		queue()
		{
			front = NULL;
			rear = NULL;
		}
		void enqueue(int x);
		int dequeue();
};

void queue::enqueue(int x)
{
	node *temp = new node;
	temp->n = x;
	temp->next = NULL;

	if (front == NULL)
	{
		front = rear = temp;
		return;
	}

	rear->next = temp;
	rear = temp;
}

int queue::dequeue()
{
	if (front == NULL)
		return K;

	node *temp = front;
	int n = temp->n;

	front = temp->next;
	delete temp;

	if (front == NULL)
		rear = NULL;

	return n;
}

int main()
{
	int q;
	cin >> q;

	queue Q;

	int op, x;
	while (q--)
	{
		cin >> op;

		if (op == 1)
		{
			int ans = Q.dequeue();

			ans == K ? cout << "Queue is empty!\n" : cout << ans << "\n";
		}

		else if (op == 2)
		{
			cin >> x;

			Q.enqueue(x);
		}
	}

	return 0;
}