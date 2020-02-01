#include<bits/stdc++.h>
using namespace std;

struct node 
{
	int data;
	struct node* left;
	struct node* right;
};


struct node* create()
{
	int n;
	printf("\nENter value or -1:");
	scanf("%d", &n);
	
	if(n==-1)
	return NULL;
	
	struct node* newnode = (struct node *)malloc(sizeof(struct node));
	
	newnode->data = n;
	cout<<"\nEnyer left child of "<<n<<":";
	newnode->left = create();
	
	cout<<"\nEnyer right child of "<<n<<":";
	newnode->right = create();
	return newnode;
	
}

void preorder(struct node * root)
{
	if(root!=NULL){
	cout<<root->data<<"  ";
	preorder(root->left);
	preorder(root->right);
	}
}

void level_order_reverse(struct node* root)
{
	stack<struct node*> s;
	queue<struct node*> q;
	
	q.push(root);
	while(!q.empty())
	{
		root = q.front();
		s.push(root);
		q.pop();
		
		if(root->right)
		q.push(root->right);
		
		if(root->left)
		q.push(root->left);
		
		
	}
	while(!s.empty())
	{
		struct node* newnode=s.top();
		cout<<newnode->data<<" ";
		s.pop();
	}
}

int main()
{
	struct node * head;
	head = create();
	preorder(head);
	cout<<"\nReverse of level order(not that thing which you are thinking) :";
	level_order_reverse(head);
}
