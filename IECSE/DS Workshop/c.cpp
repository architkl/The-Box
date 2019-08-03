#include <iostream>
using namespace std;

class Node {
public:
	int data;
	Node *next, *prev;
};

class CLL {
	Node *head;
public:
	CLL() { head = NULL; }
	void insert_front(int);
	void insert_back();
	int delete_val(int val);
	void display();
};

void CLL::insert_front(int ele) {
	Node *temp = new Node;
	temp->data = ele; temp->next = temp;
	temp->prev = temp;
	if(head == NULL) {
		head = temp;
	}
	else {
		temp->next = head;
		temp->prev = head->prev;
		(head->prev)->next = temp;
		head->prev = temp;
		head = temp;
	}
}

void CLL::insert_back(int ele) {
	Node *temp = new Node;
	temp->data = ele; temp->next = temp;
	temp->prev = temp;
	if(head == NULL) {
		head = temp;
	}
	else {
		temp->next = head;
		temp->prev = head->prev;
		(head->prev)->next = temp;
		head->prev = temp;
	}
}

int CLL::delete_val(int val) {
	Node *t = head;
	if(head == NULL)
		return -1;
	else if(head->next == head) {
		head = NULL;
	}
	else if(head->data == val) {
		t = head;
		(head->next)->prev = head->prev;
		(head->prev)->next = head->next;
	}
	else if((head->prev)->data == val) {
		t = head->prev;
		((head->prev)->prev)->next = head;
		head->prev = (head->prev)->prev;
	}
	else {
		while(t->data != val) {
			t = t->next;
		}
		t->prev->next = t->next;
		t->next->prev = t->prev;
	}
	delete t;
}