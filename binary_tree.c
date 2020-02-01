#include<stdio.h>
#include<stdlib.h>

struct node
{
	int val;
	struct node * left;
	struct node * right;
}node;

struct node * create()
{
	int n;
	printf("\nenter the value(-1 for no node): ");
	scanf("%d",&n);

	if(n == -1)
		return NULL;

	struct node * p;
	p = (struct node *)malloc(sizeof(struct node));
	p->val = n;

	printf("\nenter the left child for node %d: ", n);
	p->left = create();

	printf("\nenter the right child for node %d: ", n);
	p->right = create();

return p;
}

//preorder traversel
int disp(struct node * head)
{
	if(head != NULL)
	{
	printf("%d",head->val);
	disp(head->left);
	disp(head->right);
	}
}

void main()
{
	struct node * head = NULL;
	head = create();

	printf("\nTree created is: \n");
	disp(head);
	
}