#include <iostream>

using namespace std;

struct node
{
	int n;
	node *next;
};

class CircularLinkedList
{
	node *head;
	public:
		CircularLinkedList()
		{
			head = NULL;
		}
		void push(int x);
		void pop(int x);
		void display();
		void size();
};

void CircularLinkedList::push(int x)
{
	node *temp = new node;
	temp->n = x;

	if (head == NULL)
	{
		head = temp;
		temp->next = head;
		return;
	}

	node *ptr = head;
	while (ptr->next != head)
		ptr = ptr->next;

	ptr->next = temp;
	temp->next = head;
}

void CircularLinkedList::pop(int x)
{
	if (head == NULL)
	{
		cout << "Linked List is empty\n";
		return;
	}

	node *temp = head;
	if (head->n == x)
	{
		if (head == head->next)
		{
			head = NULL;
			delete temp;
			cout << x << " deleted\n";

			return;
		}

		else
		{
			node *ptr = head->next;
			while (ptr->next != head)
				ptr = ptr->next;

			head = head->next;
			ptr->next = head;
			delete temp;
			
			cout << x << " deleted\n";
			return;
		}
	}

	node *ptr = head ->next;
	while (ptr != head && ptr->n != x)
	{
		temp = temp->next;
		ptr = ptr->next;
	}

	if (ptr == head)
	{
		cout << "Element does not exist\n";
		return;
	}

	temp->next = ptr->next;
	delete ptr;
	cout << x << " deleted\n";
}

void CircularLinkedList::display()
{
	if (head == NULL)
	{
		cout << "Linked List is empty\n";
		return;
	}

	node *ptr = head->next;

	cout << head->n << " ";
	while (ptr != head)
	{
		cout << ptr->n << " ";
		ptr = ptr->next;
	}
	cout << "\n";
}

void CircularLinkedList::size()
{
	if (head == NULL)
	{
		cout << "Size: " << 0 << "\n";
		return;
	}

	node *ptr = head->next;
	int size = 1;

	while (ptr != head)
	{
		size++;
		ptr = ptr->next;
	}

	cout << "Size: " << size << "\n";
}

int main()
{
	int c, e;

	CircularLinkedList CL;
	
	do
	{
		cout << "1. Add Element\n"
			 << "2. Delete Element\n"
			 << "3. Display Elements\n"
			 << "4. Display Size\n"
			 << "5. Exit\n";

		cin >> c;

		switch (c)
		{
			case 1:
				cout << "Enter Element\n";
				cin >> e;
				cout << "\n\n";
				CL.push(e);
				cout << "\n\n";
				break;
			
			case 2:
				cout << "Enter Element\n";
				cin >> e;
				cout << "\n\n";
				CL.pop(e);
				cout << "\n\n";
				break;

			case 3:
				cout << "\n\n";
				CL.display();
				cout << "\n\n";
				break;

			case 4:
				cout << "\n\n";
				CL.size();
				cout << "\n\n";
				break;

			case 5:
				c = 0;
				break;

			default:
				c = 1;
		}
	} while (c);

	return 0;
}