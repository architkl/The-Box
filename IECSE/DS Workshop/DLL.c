**DOUBLY LINKED LIST**

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

	if ((*head)->data == 0)
	{
		*f = temp;
		temp->l_link = *head;
		temp->r_link = NULL;
		(*head)->r_link = temp;
		return;
	}

	temp->r_link = *f;
	temp->l_link = *head;
	(*f)->l_link = temp;
	(*head)->r_link = temp;
}

void insert_rear(NODE *head, NODE *f, int ele)
{
	NODE temp = getNode();

	temp->data = ele;

	if ((*head)->data == 0)
	{
		*f = temp;
		temp->l_link = *head;
		temp->r_link = NULL;
		(*head)->r_link = temp;
		return;
	}

	NODE last = *f;
	while (last->r_link != NULL)
		last = last->r_link;

	temp->r_link = NULL;
	temp->l_link = last;
	last->r_link = temp;
}

int delete_front(NODE *head, NODE *f)
{
	if ((*head)->data == 0)
	{
		printf("Empty List\n");
		return UF;
	}

	NODE temp = *f;
	*f = (*f)->r_link;

	if (*f != NULL)
		(*f)->l_link = *head;

	(*head)->r_link = *f;

	int ele = temp->data;
	free(temp);

	(*head)->data--;

	return ele;
}

int delete_rear(NODE *head, NODE *f)
{
	if ((*head)->data == 0)
	{
		printf("Empty List\n");
		return UF;
	}

	NODE temp = *f, prev = *head;
	while (temp->r_link != NULL)
	{
		temp = temp->r_link;
		prev = prev->r_link;
	}

	if (*f->r_link == NULL)
		*f = NULL;

	prev->r_link = NULL;

	int ele = temp->data;
	free(temp);

	(*head)->data--;

	return ele;
}

//WITHOUT HEADER

void insert_front(NODE *f, int ele)
{
	NODE temp = getNode();

	temp->data = ele;

	if (*f == NULL)
	{
		*f = temp;
		temp->l_link = NULL;
		temp->r_link = NULL;
		// (*head)->r_link = temp;
		return;
	}

	temp->r_link = *f;
	temp->l_link = NULL;
	(*f)->l_link = temp;
	// (*head)->r_link = temp;
}

void insert_rear(NODE *f, int ele)
{
	NODE temp = getNode();

	temp->data = ele;

	if (*f == NULL)
	{
		*f = temp;
		temp->l_link = NULL;
		temp->r_link = NULL;
		// (*head)->r_link = temp;
		return;
	}

	NODE last = *f;
	while (last->r_link != NULL)
		last = last->r_link;

	temp->r_link = NULL;
	temp->l_link = last;
	last->r_link = temp;
}

int delete_front(NODE *f)
{
	if (*f == NULL)
	{
		printf("Empty List\n");
		return UF;
	}

	NODE temp = *f;
	*f = (*f)->r_link;

	if (*f != NULL)
		(*f)->l_link = NULL;

	// (*head)->r_link = *f;

	int ele = temp->data;
	free(temp);

	// (*head)->data--;

	return ele;
}

int delete_rear(NODE *f)
{
	if (*f == NULL)
	{
		printf("Empty List\n");
		return UF;
	}

	NODE temp = *f, prev = NULL;
	while (temp->r_link != NULL)
	{
		prev = temp;
		temp = temp->r_link;
	}

	if (*f->r_link == NULL)
		*f = NULL;

	else
		prev->r_link = NULL;

	int ele = temp->data;
	free(temp);

	// (*head)->data--;

	return ele;
}

void display(NODE f)
{
	if (f == NULL)
	{
		printf("Empty List\n");
		return;
	}

	while (f != NULL)
	{
		printf("%s ", f->data);
		f = f->r_link;
	}
}