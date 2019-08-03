#include <iostream>
#include <stdio.h>
#include <vector>
#include <stdlib.h>
using namespace std;
struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

void merge(Node *l1, Node *l2, int s1, int s2)
{
    Node *temp1 = l1, *temp2 = l2;
    vector <int> v1(s1), v2(s2);
    // Copy data from linked list into vectors
    for (int i = 0; i < s1; i++, temp1 = temp1->next)
        v1[i] = temp1->data;
        
    for (int i = 0; i < s2; i++, temp2 = temp2->next)
        v2[i] = temp2->data;
    
    // Merge data into vector
    int i = 0, j = 0, k = 0;
    vector <int> data(s1+s2);
    while (i < s1 && j < s2)
    {
        if (v1[i] <= v2[j])
            data[k++] = v1[i++];
        
        else
            data[k++] = v2[j++];
    }
    
    while (i < s1)
        data[k++] = v1[i++];
    
    while (j < s2)
        data[k++] = v2[j++];
    
    // Copy sorted data into linked list
    for (auto itr : data)
    {
        l1->data = itr;
        l1 = l1->next;
    }
}

void actualMergeSort(Node *start, int size)
{
    if (size > 1)
    {
        Node *temp = start;
        int i = 0;
        while (i != size/2)
        {
            temp = temp->next;
            i++;
        }
        
        actualMergeSort(start, size/2);
        actualMergeSort(temp, size-size/2);
        merge(start, temp, size/2, size-size/2);
    }
}

Node* mergeSort(Node* head) {
    Node *temp = head;
    int size = 1;
    
    while (temp->next)
    {
        size++;
        temp = temp->next;
    }
    
    actualMergeSort(head, size);

    return head;
}

//Position this line where user code will be pasted.
void printList(Node* node) {
    while (node != NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("");
}
void push(struct Node** head_ref, int new_data) {
    Node* new_node = new Node(new_data);
    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}
int main() {
    long test;
    cin >> test;
    while (test--) {
        struct Node* a = NULL;
        long n, tmp;
        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> tmp;
            push(&a, tmp);
        }
        a = mergeSort(a);
        printList(a);
    }
    return 0;
}
/*This is a function problem.You only need to complete the function given below*/
/* Structure of the linked list node is as
struct Node 
{
    int data;
    struct Node* next;
    Node(int x) { data = x;  next = NULL; }
};
*/
/* Function to mergesort the linked list
   It should return head of the modified list  */