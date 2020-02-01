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

struct node* deepest(struct node * root)
{
	queue<struct node *> q;
	q.push(root);
	struct node * temp;
	
		while(!q.empty())
		{
			root = q.front();
			temp = root;
			cout<<" "<<root->data;
			
			if(root->left)
			q.push(root->left);
			if(root->right)
			q.push(root->right);
			q.pop();
		}	
		
	return temp;
}

int main()
{
	struct node * head;
	head = create();
	preorder(head);
	cout<<"\nLevel order traversal:";
	struct node * t = deepest(head);
	cout<<"\nDeepest node: "<<t->data;
}
