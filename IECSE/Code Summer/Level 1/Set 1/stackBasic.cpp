#include <iostream>

using namespace std;

const int K = 1000000000;

struct node
{
	int n;
	node *next;
};

class stack
{
	node *top;
	public:
		stack()
		{
			top = NULL;
		}
		void push(int x);
		int pop();
};

void stack::push(int x)
{
	node *temp = new node;
	temp->n = x;

	temp->next = top;
	top = temp;
}

int stack::pop()
{
	if (top == NULL)
		return K;
	
	node *temp = top;
	top = temp->next;
	
	int n = temp->n;
	delete temp;

	return n;
}

int main()
{
	int q;
	cin >> q;

	stack S;

	int op, x;
	while (q--)
	{
		cin >> op;

		if (op == 1)
		{
			int ans = S.pop();

			ans == K ? cout << "Stack is empty!\n" : cout << ans << "\n";
		}

		else if (op == 2)
		{
			cin >> x;

			S.push(x);
		}
	}

	return 0;
}