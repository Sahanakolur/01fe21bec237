#include<stdio.h>
#include<stdlib.h>
struct node
{    int data;
    struct node*link;
};
typedef struct node *NODE;
NODE creat_node();
NODE insert_front(NODE head);
NODE insert_end(NODE head);
void display(NODE head);
void display2(NODE head);
void display1(NODE head);
int main()
{
    int ch;
    NODE head=NULL;
    while(1)
    {
         printf("\n menu \n");
        printf("1:Insert front\t2:insert_end\t 3:display1 4:display2 5:display 6:exit\n");
        printf("enter your choice\n");
        scanf("%d",&ch);

                switch(ch)
                {
                    case 1 :head=insert_front(head);
                    break;
                    case 2:head=insert_end(head);
                    break;
                    case 3: display1(head);
                    break;
                    case 4: display2(head);
                    break;
                    case 5: display(head);
                    break;
                    case 6:exit(0);
                    break;
                    default :printf("invalid choice");
                    break;

                }
    }
    return 0;
}

NODE creat_node()
{
    NODE newnode;
    newnode=(NODE)malloc(sizeof(struct node));
    if (newnode==NULL)
    {
        printf("memory not allocated\n");
        exit(0);
    }
    printf("enter data\n");
    scanf("%d",&newnode->data);
    newnode->link=NULL;
    return newnode;
}
NODE insert_front (NODE head)
{
    NODE cur,newnode;
newnode= creat_node();
if (head ==NULL)
    {
            head = newnode;
            //return head;
    }
    else
    {
    cur=head;
    newnode->link=head;
    //cur -> link=newnode;
    head = newnode;
    }
    return head;
}
NODE insert_end(NODE head)
{
    NODE cur,newnode;
    newnode=creat_node();
    if (head==NULL)
    {
        head=newnode;
    }
    else
    {
        cur=head;
    while(cur->link!=NULL)
    {
        cur=cur->link;

     }
            cur->link=newnode;
            cur=newnode;
    }

        return head;

    }
void display1(NODE head)
    {
        NODE cur;
        if(head==NULL)
        {
            printf("singly linked list is cmpty\n");
        }
        else
        {
            cur=head;
             printf("postive numbers are: ");
            while(cur!=NULL)
            {
                if(cur->data>=0)
                {

                printf("%d->",cur->data);
                }
                cur=cur->link;

            }
        }

}
void display2(NODE head)
    {
        NODE cur;
        int status=0;
        if(head==NULL)
        {
            printf("singly linked list is cmpty\n");
        }
        else
        {
            cur=head;
            printf("negative numbers are:  \n");
            while(cur!=NULL)
            {
                if(cur->data<0)
                {
                  printf("%d->", cur->data);
                }

                cur=cur->link;

            }
        }
}

void display(NODE head)
    {
        NODE cur;
        if(head==NULL)
        {
            printf("singly linked list is cmpty\n");
        }
        else
        {
            cur=head;
            while(cur!=NULL)
            {

                printf("%d->",cur->data);
                cur=cur->link;

            }
        }

}
