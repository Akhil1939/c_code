#include<stdio.h>
#include<conio.h>
#include<malloc.h>
#include<stdlib.h>

struct queue
{
    int data;
    struct queue *ptr;
};
struct queue *front=NULL,*rear=NULL,*temp;
void insert(int x)
{
    temp=(struct queue *)malloc(sizeof(struct queue));
    temp->data=x;
    temp->ptr=NULL;
    if(rear==NULL && front==NULL)
    {
        front=temp;
        rear=temp;
    }
    else
    {
        rear->ptr=temp;
        rear=rear->ptr;
    }
}
int remove1()
{
    int x;
    if(front==NULL && rear==NULL)
    {
        printf("\n queue is empty");
        return(-1);
    }
    else
    {
        temp=front;
        front=front->ptr;
        x=temp->data;
        free(temp);
        return(x);
        }
}
display()
{
    for(temp=front;temp!=NULL;temp=temp->ptr)
    {
        printf(" %d ",temp->data);
    }
}
void main()
{
    int ch,x;
    while(1)
    {
        printf("\n 1. insert");
        printf("\n 2. remove");
        printf("\n 3. display");
        printf("\n 4. exit");
        printf("\n emnter your choice :");
        scanf("%d",&ch);
        switch(ch)
        {
        case 1:
            printf("\n enter data to be insert");
            scanf("%d",&x);
            insert(x);
            getch();
            break;
        case 2:
            x=remove1();
            printf("\n ");
            break;
        case 3:
            display();
            getch();
            break;
        case 4:
            exit(0);
        }
    }
}
