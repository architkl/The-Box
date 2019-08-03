#include <iostream>

using namespace std;

struct node
{
	int n;
	node *next;
};

class LinkedList
{
	node *head;
	public:
		LinkedList()
		{
			head = NULL;
		}
		void push(int x);
		void pop(int x);
		void display();
		void size();
};

void LinkedList::push(int x)
{
	node *temp = new node;
	temp->n = x;
	temp->next = NULL;

	if (head == NULL)
	{
		head = temp;
		return;
	}

	node *ptr = head;
	while (ptr->next != NULL)
		ptr = ptr->next;

	ptr->next = temp;
}

void LinkedList::pop(int x)
{
	if (head == NULL)
	{
		cout << "Linked List is empty\n";
		return;
	}

	node *temp = head;
	if (head->n == x)
	{
		head = head->next;
		delete temp;
		return;
	}

	node *ptr = head ->next;
	while (ptr != NULL && ptr->n != x)
	{
		temp = temp->next;
		ptr = ptr->next;
	}

	if (ptr == NULL)
	{
		cout << "Element does not exist\n";
		return;
	}

	temp->next = ptr->next;
	delete ptr;
	cout << x << " deleted\n";
}

void LinkedList::display()
{
	if (head == NULL)
	{
		cout << "Linked List is empty\n";
		return;
	}

	node *ptr = head;
	while (ptr != NULL)
	{
		cout << ptr->n << " ";
		ptr = ptr->next;
	}
	cout << "\n";
}

void LinkedList::size()
{
	node *ptr = head;
	int size = 0;

	while (ptr != NULL)
	{
		size++;
		ptr = ptr->next;
	}

	cout << "Size: " << size << "\n";
}

int main()
{
	int c, e;

	LinkedList L;
	
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
				L.push(e);
				cout << "\n\n";
				break;
			
			case 2:
				cout << "Enter Element\n";
				cin >> e;
				cout << "\n\n";
				L.pop(e);
				cout << "\n\n";
				break;

			case 3:
				cout << "\n\n";
				L.display();
				cout << "\n\n";
				break;

			case 4:
				cout << "\n\n";
				L.size();
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