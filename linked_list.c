#include<stdio.h>
#include<stdlib.h>

typedef struct nodes 
{
    int data;
    struct nodes* next;
}nodes;

    nodes * append_nodes(nodes* head, int value)
    {
        nodes * temp, *p;
        p = head;
        
        if(head == NULL)
        {
            head->data = value;    
        }
        else
        {
            temp = (nodes *)malloc(sizeof(nodes));
            while(p->next!= NULL)
            {
                p = p->next;
                printf("\ndata: %d",p->data);
            }
            temp->data = value;
            temp->next = NULL;
            p->next = temp;
        }        
        return head;
    }

    void display(nodes * head)
    {
        nodes * temp ;
        temp = (nodes *)malloc(sizeof(nodes));
        temp = head;
        printf("\n Linked list is: ");
        while(temp!=NULL)
        {
            printf("%d-->", temp->data);
            temp = temp->next;
        }
    }

    nodes * insert_nodes(nodes * head, int value, int check)
    {
        nodes *p, *temp, * prev;
        p = head;
        if(head == NULL)
        {
            head->data = value;    
        }

        if (check == 1)
        {
            temp = (nodes *)malloc(sizeof(nodes));
            temp->data = value;
            temp->next = head;
            head = temp;
            return head;
            printf("\nElement added succesfully\n");       
        }

        if(check == 2)
        {
            int after;
            printf("\nEnter the value after which to insert the element:");
            scanf("%d",&after);
            while(p != NULL && p->data !=after )
            {
                prev = p;
                p = p->next;
            }
            temp = (nodes *)malloc(sizeof(nodes));
            temp->data = value;
            
            temp->next = p->next;
            p->next = temp;
            return head;
            printf("\nElement added succesfully\n");
        }

        if (check == 3)
        {
            while(p->next != NULL )
            {
                p = p->next;
            }
            temp = (nodes *)malloc(sizeof(nodes));
            temp->data = value;
            temp->next = NULL;
            p->next = temp;
            return head;
            printf("\nElement added succesfully\n");
        }
        
       
    }

    nodes * delete_node(nodes * head, int value)
    {
        nodes * p, *prev;
        p = (nodes *)malloc(sizeof(nodes));
        p=head;        
        if(p == NULL)
        {
            printf("\nLinked List is empty");
            return 0;
        }

        if (p->data == value)
        {
            head = p->next;
            return head;
            printf("\nElement deleted succesfully\n");
        }

        while(p != NULL && p->data != value)
        {
            prev = p;
            p = p->next;
        }  

        prev->next = p->next;    
        free(p);
        printf("\nElement deleted succesfully\n");   
        return head; 
    }

int main()
{
    int ch, value,check;
    nodes *  head;
    // printf("%d\n",head);
    // printf("nodes created:");
    printf("\nCreate a head node first:");
    scanf("%d",&value);
    head = (nodes *)malloc(sizeof(nodes));
    head->next = NULL;
    head->data = value;
    
    do
    {
         printf("\n\n-----MENU-----\n1.Append \n2.Insert \n3.Delete \n4.Display \n5.exit\n\n Enter your choice : ");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1: 
            printf("\nEnter the value to be appended:");
            scanf("%d",&value);
            head = append_nodes(head, value);
            break;

            case 2:
            printf("\nEnter the element to be inserted:");
            scanf("%d",&value);
            printf("\nWhere to insert the element? \n Press 1 for Beginning\n Press 2 for Middle\n Press 3 for Last\n Enter your choice: "); 
            scanf("%d",&check);
            head = insert_nodes(head, value,check);
            break;

            case 3:
            printf("\nenter the element to be deleted:");
            scanf("%d",&value);
            head = delete_node(head, value);
            break;

            case 4: display(head);
            break;
        }
        
    } while (ch!=-1);
    
}