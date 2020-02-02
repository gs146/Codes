#include<bits/stdc++.h>

using namespace std;

typedef struct node
{
    int data;
    struct node* left;
    struct node* right;
}node;

node * create_tree()
{
    int t;
    cout<<"\nEnter the data or -1:";
    cin>>t;

    if(t == -1)
    return NULL;

    node* newnode = (node*)malloc(sizeof(node *));
    newnode->data = t;
    cout<<"\nEnter the value for left child of node "<<t<<":";
    newnode->left = create_tree();

    cout<<"\nEnter the value for right child of node "<<t<<":";
    newnode->right = create_tree();
} 

void inorder(node * root)
{
    if(root)
    {
        inorder(root->left);
        cout<<root->data<<"  ";
        inorder(root->right);
    }
}
int f=0;
void path_with_sum(node * root, int sum,int check, stack<node*>s,stack<node*>temp)
{
      
    if(root)
    {
        s.push(root);
        check += root->data;
        if(check == sum)
        {
            //print(stack)
            temp = s;
            cout<<"\nPath with given sum "<<sum<<"is:";
            while(!s.empty())
            {
                node * n = s.top();
                cout<<n->data<<"->";
                s.pop();
                
            }
            f = 1;
        }
        
        path_with_sum(root->left,sum,check,s,temp);
        path_with_sum(root->right,sum,check,s,temp);
        check -= root->data;
        s.pop();
    }
    if(f==0)
    {
        cout<<"\nNo such path in the graph\n";
        
    }
    
}

int main()
{
    node* head;
    head = create_tree();
    cout<<"\nInorder traversel of tree: ";
    inorder(head); 

    int sum;
    cout<<"\nEnter the sum to be checked:";
    cin>>sum;
    stack <node*> s;
    stack <node*> temp;
    path_with_sum(head,sum,0,s,temp);
    return 0;
}