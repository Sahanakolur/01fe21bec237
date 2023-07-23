//Write a program to represent a dequeue using linked list, also write function add and delete from the dequeue.
#include<stdio.h>

#include<stdlib.h>

#define SIZE 100

struct queue
{
    int data;
struct queue *r_link;
struct queue *l_link;

}; typedef struct queue*NODE;

NODE create_node();
NODE enqueue_end(NODE head);
NODE dequeue_front(NODE head);
NODE enqueue_front(NODE head);
NODE dequeue_end(NODE head);
void display(NODE head);
int main()
{

 NODE head=NULL;

int k;

while(1)

{
 printf("\n1:enqueue_end 2:dequeue_front 3:display 4:enqueue_front 5:dequeue_end \n");

  printf("Enter your choice\n");

 scanf("%d",&k);

 if(k==1)
 {
     head=enqueue_end(head);
 }

 else if(k==2)
 {

        head=dequeue_front(head);
 }
    else if(k==3)
    {
        display(head);
   }
    else if(k==4)
    {
        head=enqueue_front(head);
   }
    else if(k==5)
    {
     head=dequeue_end(head);
    }
 }
}

NODE create_node()
{
    NODE newnode;
newnode=(NODE)malloc(sizeof(struct queue));
if(newnode==NULL)
{
    printf("memory  is not allocated");
    exit(0);
}
printf("Enter data\n");
scanf("%d",&newnode->data);
printf("enqueued is %d",&newnode->data);
    newnode->r_link=NULL;
newnode->l_link=NULL;
return newnode;
}

NODE enqueue_end(NODE head)
{ NODE cur=head;
NODE newnode=create_node();
if(head==NULL)
{
    head=newnode;
}
else
{
    while(cur->r_link!=NULL)
    {
        cur=cur->r_link;
    }
    cur->r_link=newnode;
    newnode->l_link=cur;
}
   return head;
}
NODE dequeue_front(NODE head)
{
NODE cur;
if(head==NULL)
{
    printf("is empty");
}
else
{
    if(head->r_link==NULL&&head->l_link==NULL)
    {
        printf("deleted %d %d",head->data,&head->data);
        free(head);
        head=NULL;
    }
    else
    {
        cur=head;
        head=cur->r_link;
        printf("Deleted %d %d",cur->data,&cur->data);
        cur->r_link=NULL;
        free(cur);
    }
    return head;
}
}
 void display(NODE head)
{
NODE cur;
if(head==NULL)
{
    printf("is empty\n");
}
else
{
        cur=head;
    while(cur!=NULL)
    {
        printf("%d  %d\n",cur->data,&cur->data);
        cur=cur->r_link;
    }
  }
}

NODE enqueue_front(NODE head)
{
NODE cur=head;
NODE newnode=create_node();
if(head==NULL)
{
    head=newnode;
}
else
{
    newnode->r_link=head;
    head=newnode;
}
return head;
}
 NODE dequeue_end(NODE head)
{
 NODE cur,prev;
if(head==NULL)
{
    printf("is empty");
}
else
{
    if(head->r_link==NULL&&head->l_link==NULL)
    {
        printf("deleted %d %d",head->data,&head->data);
        free(head);
        head=NULL;
    }
    else
    {
        cur=head;
        prev=NULL;
        while(cur->r_link!=NULL)
        {
            prev=cur;
            cur=cur->r_link;
        }
        prev->r_link=NULL;
        printf("Deleted %d %d",cur->data,&cur->data);
        free(cur);
    }
    return head;
 }
}
