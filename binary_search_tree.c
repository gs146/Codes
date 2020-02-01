#include<stdio.h>
#include<stdlib.h>

struct node 
{
	int val;
	struct node* left;
	struct node* right;
}node;

struct node* newnode(int data)
{
	struct node * temp = (struct node *)malloc(sizeof(struct node));
	temp -> val =data;
	temp -> left = temp -> right = NULL;
	return temp;
}

struct node * insert(struct node * root, int value)
{
	
	if(root == NULL)
	{
		root = newnode(value);
	}

	else if(value <= root->val)
		root->left = insert(root->left, value);

	else
		root->right = insert(root->right, value);

	return root;
}

void disp(struct node * root)
{
	if(root != NULL)
	{
		printf("%d ", root->val);
		disp(root->left);
		disp(root->right);
	}
}

void main()
{
	int t,ch;
	struct node * root = NULL;
	while(1)
	{
		printf("\nEnter nodes in bst: ");
		scanf("%d",&t);
		root = insert(root, t);
		printf("\nWant to enter more nodes in bst(1/0): ");
		scanf("%d",&ch);
		if(ch == 0)
			break;
		else
			continue;
	}

	disp(root);
}