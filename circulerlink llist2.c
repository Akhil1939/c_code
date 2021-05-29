#include<stdio.h>
#include<conio.h>
#include<malloc.h>
#include<stdlib.h>

struct list
{
    int data;
    struct list *next;
};
struct list *start=NULL,*node=NULL;


void create()
{
    char ch;
    start=(struct list *)malloc(sizeof(struct list));
    printf("\n enter data: ");
    scanf("%d",&start->data);

    start->next=start;

    printf("\n wants to create more nodes(y/n): ");
    ch=getch();

    node=start;

    while(ch=='y')
    {

        node->next=(struct list*)malloc(sizeof(struct list));
        node=node->next;
        printf("\n enter node data: ");
        scanf("%d",&node->data);
        node->next=start;
        printf("\n wants to create more nodes(y/n): ");
        ch=getch();
    }

}

void display()
{

    node=start;
    printf("\n %d",node->data);
    node=node->next;
    while(node!=start)
    {

        printf("\n %d",node->data);
        node=node->next;
    }
}

void insert_begin()
{
    struct list *ptr;
    ptr=(struct list *)malloc(sizeof(struct list));
    printf("\n enter new node data :");
    scanf("%d",&ptr->data);
    ptr->next=start;
    start=ptr;
}

void insert_last()
{
    struct list *ptr,*temp;
    ptr=(struct list *)malloc(sizeof(struct list));
    printf("\n enter new node data:");
    scanf("%d",&ptr->data);
    ptr->next=NULL;

    temp=start;
    while(temp)
    {
        if(temp->next==NULL)
        {
            temp->next=ptr;
        }
        else
        {
            temp=temp->next;
        }
    }
}

void insert_after_desired()
{
    struct list *ptr,*temp;
    int x;

    printf("\n enter desired node data");
    scanf("%d",&x);

    temp=start;

    while(temp)
    {
        if(temp->data==x)
        {
           ptr=(struct list *)malloc(sizeof(struct list));
           printf("\n enter new node data");
           scanf("%d",&ptr->data);
           ptr->next=temp->next;
           temp->next=ptr;
           break;
        }
        else
        {
            temp=temp->next;
        }
    }
}

void sort()
{
    struct list *p1,*p2;
    int temp;

    for(p1=start;p1->next!=NULL;p1=p1->next)
    {
        for(p2=start;p2!=NULL;p2=p2->next)
        {
            if(p2->data > p2->next->data)
            {
                temp=p2->data;
                p2->data=p2->next->data;
                p2->next->data=temp;
            }
        }
    }
}
void main()
{
    int ch ;
    while(1)
    {
        printf("\n 1.create linked list");
        printf("\n 2.display");
        printf("\n 3. Insret new node at bigining");
        printf("\n4. insert new node at and ");
        printf("\n 5. insert a new node after desure node");
        printf("\n 6.exit");

        printf("\n enter your choice : ");
        scanf("%d",&ch);

        switch(ch)
        {
        case 1:
            create();
            getch();
            break;

        case 2:
            display();
            getch();
            break;

        case 3:
            insert_begin();
            getch();
            break;
        case 4:
            insert_last();
            getch();
            break;
        case 5:
            insert_after_desired();
            getch();
            break;
        case 6:
            exit(0);


        default:
            printf("\n wrong choice");
            getch();
        }
    }
}

