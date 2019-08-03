**SINGLY LINKED LIST**

#define UF -99999

class NODE
{
	public:
		int data;
		NODE *next;
};

typedef struct node
{
	int data;
	struct node *next;
} *NODE;

NODE getNode()
{
	// NODE x = new NODE;

	NODE x = (NODE)malloc(sizeof(struct node));
	return x;
}

// HEADER

void insert_front(NODE *head, NODE *f, int ele)
{
	NODE temp = getNode();

	temp->data = ele;
	temp->next = NULL;

	if ((*head)->data == 0)
	{
		*f = temp;
		(*head)->next = *f;
		(*head)->data++;
		return;
	}

	temp->next = *f;
	*f = temp;
	(*head)->next = temp;
	(*head)->data++;
}

void insert_rear(NODE *head, NODE *f, int ele)
{
	NODE temp = getNode();

	temp->data = ele;
	temp->next = NULL;

	if ((*head)->data == 0)
	{
		*f = temp;
		(*head)->next = *f;
		(*head)->data++;
		return;
	}

	NODE cur = *f;
	while (cur->next != NULL)
		cur = cur->next;

	cur->next = temp;
	(*head)->data++;
}

int delete_front(NODE *head, NODE *f)
{
	if ((*head)->data == 0)
	{
		printf("List is empty\n");
		return UF;
	}

	NODE temp = *f;
	*f = (*f)->next;
	(*head)->next = *f;

	int ele = temp->data;
	free(temp);

	(*head)->data--;
	return ele;
}

int delete_rear(NODE *head, NODE *f)
{
	if ((*head)->data == 0)
	{
		printf("List is empty\n");
		return UF;
	}

	NODE prev = *head, temp = *f;
	while (temp->next != NULL)
	{
		temp = temp->next;
		prev = prev->next;
	}

	prev->next = NULL;

	int ele = temp->data;
	free(temp);

	(*head)->data--;
	return ele;
}

void display(NODE head, NODE f, NODE r)
{
	printf("Nodes: %d\n", head->data);
	if (head->data == 0)
	{
		printf("List is empty\n");
		return;
	}

	NODE temp = f;
	while (temp != NULL)
	{
		printf("%d ", temp->data);
		temp = temp->next;
	}
	printf("\n");
}

// WITHOUT HEADER

void insert_front(NODE *f, int ele)
{
	Node temp = getNode();

	temp->data = ele;
	temp->next = NULL;

	if (*f == NULL)
	{
		*f = temp;
		// (*head)->next = *f;
		// (*head)->data++;
		return;
	}

	temp->next = *f;
	*f = temp;
	// (*head)->next = temp;
	// (*head)->data++;
}

void insert_rear(NODE *f, int ele)
{
	NODE temp = getNode();

	temp->data = ele;
	temp->next = NULL;

	if (*f == NULL)
	{
		*f = temp;
		// (*head)->next = *f;
		// (*head)->data++;
		return;
	}

	NODE cur = *f;
	while (cur->next != NULL)
		cur = cur->next;

	cur->next = temp;
	// (*head)->data++;
}

int delete_front(NODE *f)
{
	if (*f == NULL)
	{
		printf("List is empty\n");
		return UF;
	}

	NODE temp = *f;
	*f = (*f)->next;
	// (*head)->next = *f;

	int ele = temp->data;
	free(temp);

	// (*head)->data--;
	return ele;
}

int delete_rear(NODE *f)
{
	if (*f == NULL)
	{
		printf("List is empty\n");
		return UF;
	}

	NODE prev = NULL, temp = *f;
	while (temp->next != NULL)
	{
		prev = temp;
		temp = temp->next;
	}

	if (temp == *f)
		*f = NULL;

	else
		prev->next = NULL;

	int ele = temp->data;
	free(temp);

	// (*head)->data--;
	return ele;
}