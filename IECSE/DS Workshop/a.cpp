#include <iostream>
using namespace std;

class Node {
public:
	int data;
	Node *next;
};

class LL {
	Node *head;
public:
	void insert_front();
	void insert_back();
	int Delete_front();
	int Delete_back();
	void display();
};

void LL::insert_front() {
	Node temp = new Node;

	temp->data = ele;
	temp->next = NULL;

	if (head == NULL)
		head = temp;

	else
		temp->next = head;
}

void LL::insert_back() {
	Node temp = new Node;

	temp->data = ele;
	temp->next = NULL;

	if (head == NULL)
	{
		head = temp;
		return;
	}

	Node *t = head;
	while (t->next != NULL)
		t = t->next;

	t->next = temp;
}

int LL::delete_val(int val) {
	if (head == NULL)
	{
		cout << "LOL EMPTY\n";
		return -99999;
	}

	Node *t = head, *p = NULL;

	if (head->data == val)
	{
		head = head->next;
		delete(t);
		return;
	}

	while (t->data != val && t != NULL) {
		p = t;
		t = t->next;
	}

	if (t == NULL) {
		cout << "LOL DOESN'T EXIST\n";
		return -99999;
	}

	p->next = t->next;
	delete(t);

	return val;
}

int LL::delete_pos(int pos) {
	if (head == NULL) {
		cout << "LOL EMPTY\n";
		return -99999;
	}

	int c = 1;
	Node *t = head, *p = NULL;
	while (t != NULL && c != pos) {
		p = t;
		t = t->next;
		c++;
	}

	if (t == NULL) {
		cout << "OUT OF BOUNDS\n";
		return -99999;
	}

	int v;

	if (pos == 1) {
		v = head->data;
		head = head->next;
		delete(t);
	}

	else {
		v = t->data;
		p->next = t->next;
		delete(t);
	}

	return v;
}




































class Node {
public:
	int data;
	Node *prev, *next;
};

class LL {
	Node *head;
public:
	void insert_front(int);
	void insert_back(int);
	int Delete_front();
	int Delete_back();
	void display();
};

void insert_front(int ele)
{
	NODE *temp = new Node;

	temp->data = ele;
	temp->next = temp->prev = NULL;

	if (head == NULL)
	{
		head = temp;
		return;
	}

	temp->next = head;
	head->prev = temp;
	head = temp;
}

void insert_back(int ele)
{
	Node *temp = new Node;

	temp->data = ele;
	temp->prev = temp->next = NULL;

	if (head == NULL)
	{
		head = temp;
		return;
	}

	NODE *t = head;
	while (t->next != NULL)
		t = t->next;

	t->next = temp;
	temp->prev = t;
}

int DLL::delete_val(int val)
{
	Node *t = head;

	if (head == NULL)
	{
		cout << "EMPTY\n";
		return -99999;
	}

	while (t != NULL && t->data != val)
		t = t->next;
	
	if (t == NULL)
	{
		cout << "DOESN'T EXIST\n";
		return -99999;
	}

	if (head->data == val)
	{
		head = head->next;
		head->prev = NULL;

		delete(t);

		return val;
	}

	if (t->next == NULL)
	{
		(t->prev)->next = t->next;
		
		delete(t);
		
		return val;
	}

	(t->prev)->next = t->next;
	(t->next)->prev = t->prev;

	delete(t);

	return val;
}