#include <iostream>
using namespace std;

class Node {
public:
	int data;
	Node *next;
};

class CLL {
	Node *head;
public:
	CLL() { head = NULL; }
	void insert_front();
	void insert_back();
	int Delete(int val);
	void display();
};

void CLL::insert_front() {
	Node *temp = new Node;
	cin >> temp->data;
	temp->next = NULL;
	if(head == NULL) {
		head = temp;
		head->next = head;
	}
	Node *t = head;
	while(t->next != head) {
		t = t->next;
	}
	temp->next = t->next;
	t->next = temp;
	head = temp;
}

void CLL::insert_back() {
	Node *temp = new Node;
	cin >> temp->data;
	temp->next = NULL;
	if(head == NULL) {
		head = temp;
		head->next = head;
	}
	else {
		Node *t = head;
		while(t->next != head)
			t= t->next;
		temp->next = t->next;
		t->next = temp;
	}
}

int CLL:delete_val(int val) {
	N
}