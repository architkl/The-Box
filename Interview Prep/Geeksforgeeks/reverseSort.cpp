struct Node * mergeResult(Node *node1,Node *node2)
{
    Node *final = new Node(), *temp1 = node1, *temp2 = node2;
    Node *temp3 = final;
    
    while (temp1 && temp2)
    {
        if (temp1->data <= temp2->data)
        {
            temp3->data = temp1->data;
            temp1 = temp1->next;
        }
        
        else
        {
            temp3->data = temp2->data;
            temp2 = temp2->next;
        }
        
        temp3->next = new Node();
        temp3 = temp3->next;
    }
    
    while (temp1)
    {
        temp3->data = temp1->data;
        
        if (temp1->next == NULL)
        {
            temp3->next = NULL;
            break;
        }
        
        temp1 = temp1->next;
        temp3->next = new Node();
        temp3 = temp3->next;
    }
    
    while (temp2)
    {
        temp3->data = temp2->data;

        if (temp2->next == NULL)
        {
            temp3->next = NULL;
            break;
        }

        temp2 = temp2->next;
        temp3->next = new Node();
        temp3 = temp3->next;
    }

    temp3 = final;
    Node *prev = NULL, *nxt;
    while (temp3)
    {
        nxt = temp3->next;
        temp3->next = prev;

        prev = temp3;
        temp3 = nxt;
    }

    return prev;
}