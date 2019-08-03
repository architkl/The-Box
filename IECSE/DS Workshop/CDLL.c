**CIRCULAR DOUBLY LINKED LIST**

#define UF -99999

NODE getNode()
{
	NODE x = (NODE)malloc(sizeof(struct node));
	return x;
}

//HEADER

void insert_front(NODE *head, int ele)
{
	NODE temp = getNode();

	temp->data = ele;

	temp->r_link = head->r_link;
	((*head)->r_link)->l_link = temp;
	(*head)->r_link = temp;
	temp->l_link = *head;
	
	(*head)->data++;
}

void insert_rear(NODE *head, int ele)
{
	NODE temp = getNode();

	temp->data = ele;

	temp->l_link = head->l_link;
	((*head)-l_link)->r_link = temp;
	temp->r_link = head;
	head->l_link = temp;
}

int delete_front(NODE *head)
{
	if ((*head)->data == 0)
	{
		printf("Empty List\n");
		return UF;
	}

	NODE temp = head->r_link;

	(temp->r_link)->l_link = *head;
	(*head)->r_link = temp->r_link;

	int ele = temp->data;
	free(temp);

	(*head)->data--;

	return ele;
}

int delete_rear(NODE *head)
{
	if ((*head)->data == 0)
	{
		printf("Empty List\n");
		return UF;
	}

	NODE temp = head->l_link;

	(temp->l_link)->r_link = *head;
	(*head)->l_link = temp->l_link;

	int ele = temp->data;
	free(temp);

	(*head)->data--;

	return ele;
}

void display(NODE head)
{
	if (head->data == 0)
	{
		printf("Empty List\n");
		return;
	}

	NODE temp = head->l_link;

	while (temp != head)
	{
		printf("%d", temp->data);
		temp = temp->l_link;
	}
	printf("\n");
}