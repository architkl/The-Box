**CIRCULAR SINGLY LINKED LIST**

#define UF -99999

NODE getNode()
{
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
		temp->next = *f;
		(*head)->next = *f;
		(*head)->data++;
		return;
	}

	NODE last = *f;
	while (last->next != *f)
		last = last->next;

	temp->next = *f;
	last->next = temp;
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
		temp->next = *f;
		(*head)->next = *f;
		(*head)->data++;
		return;
	}

	NODE last = *f;
	while (last->next != *f)
		last = last->next;

	temp->next = *f;
	last->next = temp;
	(*head)->data++;
}

int delete_front(NODE *head, NODE *f)
{
	if ((*head)->data == 0)
	{
		printf("List is empty\n");
		return UF;
	}

	NODE temp = *f, last = *f;
	while (last->next != *f)
		last = last->next;

	*f = (*f)->next;
	(*head)->next = *f;
	last->next = *f;

	if (temp == *f)		//((*head)->data == 1), ((*f)->next == *f)
		*f = NULL;

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

	NODE temp = *f, prev = *head;
	while (temp->next != *f)
	{
		temp = temp->next;
		prev = prev->next;
	}

	if (temp == *f)		//((*head)->data == 1), ((*f)->next == *f)
		*f = NULL;

	prev->next = *f;

	int ele = temp->data;
	free(temp);

	(*head)->data--;
	return ele;
}

// WITHOUT HEADER

void insert_front(NODE *f, int ele)
{
	NODE temp = getNode();

	temp->data = ele;
	temp->next = NULL;

	if (*f == NULL)
	{
		*f = temp;
		temp->next = *f;
		// (*head)->next = *f;
		// (*head)->data++;
		return;
	}

	NODE last = *f;
	while (last->next != *f)
		last = last->next;

	temp->next = *f;
	last->next = temp;
	*f = temp;
	// (*head)->next = temp;
	// (*head)->data++;
}

void insert_rear(NODE *f, int ele)
{
	NODE temp = getNode();
	
	temp->data = ele;
	temp->next = NULL;

	if (*first == NULL)
	{
		temp->next = temp;
		*first = temp;
		// (*head)->next = *f;
		// (*head)->data++;
		return;
	}

	NODE last = *f;
	while (last->next != *f)
		last = last->next;

	temp->next = *f;
	last->next = temp;
	// (*head)->data++;
}

int delete_front(NODE *f)
{
	if (*f == NULL)
	{
		printf("List is empty\n");
		return UF;
	}

	NODE temp = *f, last = *f;
	while (last->next != *f)
		last = last->next;

	*f = (*f)->next;
	// (*head)->next = *f;
	last->next = *f;

	if (temp == *f)		//((*f)->next == *f)
		*f = NULL;

	int ele = temp->data;
	free(temp);

	(*head)->data--;
	return ele;
}

int delete_rear(NODE *f)
{
	if (*f == NULL)
	{
		printf("List is empty\n");
		return UF;
	}

	NODE temp = *f, prev = NULL;
	while (temp->next != *f)
	{
		prev = temp;
		temp = temp->next;
	}

	if (temp == *f)		//((*f)->next == *f)
		*f = NULL;

	else
		prev->next = *f;

	int ele = temp->data;
	free(temp);

	// (*head)->data--;
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
	do
	{
		printf("%c ", temp->data);
		temp = temp->next;
	} while (temp != f);
	printf("\n");
}