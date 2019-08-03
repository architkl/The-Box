#include <iostream>

using namespace std;

struct node
{
	int n;
	node *prev, *next;
};

class DoublyLinkedList
{
	node *head;
	public:
		DoublyLinkedList()
		{
			head = NULL;
		}
		void push(int x);
		void pop(int x);
		void display();
		void size();
};

void DoublyLinkedList::push(int x)
{
	node *temp = new node;
	temp->n = x;
	temp->next = NULL;

	if (head == NULL)
	{
		head = temp;
		temp->prev = NULL;
		return;
	}

	node *ptr = head;
	while (ptr->next != NULL)
		ptr = ptr->next;

	ptr->next = temp;
	temp->prev = ptr;
}

void DoublyLinkedList::pop(int x)
{
	if (head == NULL)
	{
		cout << "Linked List is empty\n";
		return;
	}

	node *temp = head;
	while (temp != NULL && temp->n != x)
		temp = temp->next;

	if (temp == NULL)
	{
		cout << "Element does not exist\n";
		return;
	}

	if (temp == head)
	{
		head = head->next;
		delete temp;
		cout << x << " deleted\n";
		return;
	}

	(temp->prev)->next = temp->next;
	delete temp;
	cout << x << " deleted\n";
}

void DoublyLinkedList::display()
{
	if (head == NULL)
	{
		cout << "Linked List is emoty\n";
		return;
	}

	node *ptr = head;

	while (ptr != NULL)
	{
		cout << ptr->n << " ";
		ptr = ptr->next;
	}
}

void DoublyLinkedList::size()
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

	DoublyLinkedList DL;
	
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
				DL.push(e);
				cout << "\n\n";
				break;
			
			case 2:
				cout << "Enter Element\n";
				cin >> e;
				cout << "\n\n";
				DL.pop(e);
				cout << "\n\n";
				break;

			case 3:
				cout << "\n\n";
				DL.display();
				cout << "\n\n";
				break;

			case 4:
				cout << "\n\n";
				DL.size();
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