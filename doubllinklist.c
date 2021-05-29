#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<ctype.h>
#define new_node (struct dlist *)malloc(sizeof(struct dlist))

//MAKING A DOUBLY LINKED LIST
struct dlist{
    struct dlist *prev;
    int data;
    struct dlist *next;
};

struct dlist *start=NULL, *temp, *node;



void create();
void display_forward();
void display_backward();
void insert_first();

void create()
{
    char ch;
    //IF LIST IS CREATED, GO TO IF CONDITION
    if(start != NULL)
    {
        printf("\n \t D List is already created...");
    }
    //MAKING A FIRST NODE NAMED START
    //SET IT'S PREV & NEXT BOTH NULL
    //IF YOU WANT TO ADD MORE DATA, GO TO WHILE LOOP
    //IT WILL STORE VALUES AFTER BY AFTER UNTIL YOU SAY 'n'
    else
    {
        start = (struct dlist *)malloc(sizeof(struct dlist));
        printf("\nEnter data - ");;
        scanf("%d", &start->data);
        start->prev = NULL;
        start->next = NULL;

        fflush(stdin);
        printf("Want to create more data - (y/n) - ");
        scanf("%c", &ch);
        node = start;
        while(ch == 'y')
        {
            node->next = (struct dlist *)malloc(sizeof(struct dlist));
            node->next->prev = node;
            node = node->next;
            printf("\nEnter data - ");
            scanf("%d", &node->data);
            node->next = NULL;

            fflush(stdin);
            printf("\nWant to create more data - (y/n)");
            scanf("%c", &ch);
        }
    }
}

//DISPLAYS ALL VALUES FROM START
void display_forward()
    {
        node = start;
        while(node->next != NULL)
        {
            printf("\n%d", node->data);
            node = node->next;
        }
        printf("\n%d", node->data);
        printf("\n\tProcess done..");
    }

//DISPLAYS ALL VALUES FROM REVERSE
void display_backward()
{
    node = start;
    while (node->next != NULL)
    {
        node = node->next;
    }
    while (node->prev != NULL)
    {
        printf("\n%d",node->data);
        node = node->prev;
    }
    printf("\n%d",node->data);


}


//INSERTING VALUE AT FIRST OR YOU CAN SAY START NODE
void insert_first()
{
    if(start == NULL)
    {
        printf("\n\t D list is empty...");
    }
    else
    {
        start->prev = new_node;
        start->prev->next = start;
        start = start->prev;
        printf("\nEnter data - ");
        scanf("%d", &start->data);
        start->prev = NULL;
        printf("\n\t Process done...");
    }

}

void insert_last()
{
    temp=(struct dlist *)malloc(sizeof(struct dlist));
    printf("\n enter node data");
    scanf("%d",&temp->data);
    node=start;
    while(node)
    {
        if(node->next==NULL)
        {
            temp->prev=node;
            node->next=NULL;
            node->next=temp;
        }
        else{node=node->next;
        }
    }
}

void insret_desired()

{
    int x;

    printf("\n enter desired node data :");
    scanf("%d",&x);

    node=start;

    while(node)
    {
         if(node->data==x)
         {
             temp=(struct dlist *)malloc(sizeof(struct dlist));
             printf("\n  enter node data");
             scanf("%d",&temp->data);

             temp->next=node->next;
             node->next->prev=temp;

             temp->prev=node;
             node->next=temp;
             break;
         }
         else{
            node=node->next;
         }
    }
}

void delete_first()

{
    temp=start;

    start=start->next;
    start->prev=NULL;
    printf("\n tne deleted node=%d",temp->data);
    free(temp);

}

void delete_last()
{
    node=start;
    while(node)
    {
    if(node->next==NULL)
    {
        node->prev->next=NULL;
        free(temp);
        break;
    }
    else{
        node->next;
    }
    }
}

void delete_desired()
{
    int x;
    printf("\n which is your derised node :");
    scanf("%d",&x);
    while(node)
    {
        if(node->data==x)
        {
            node->next->prev=node->prev;
            node->prev->next=node->next;
            printf("\n deleted node= %d",node->data);
        }
        else{
            node->next;
        }
    }
}

//MENU DRIVEN FUNCTION
int main()
    {
        int choice;
        while(1)
        {
            printf("\n========================");
            printf("\n 1. Create D List");
            printf("\n 2. Insert First ");
            printf("\n 3. Display in Forward");
            printf("\n 4. Display in Reverse");
            printf("\n 5. insert at last");
            printf("\n 6. insert  node after desire node: ");
            printf("\n 7. delete first node:");
            printf("\n 8. delete last node");
            printf("\n 9. delete desire node:");
            printf("\n 10. Exit");
            printf("\n========================");
            printf("\n Enter a choice - ");
            scanf("%d", &choice);

            switch (choice)
            {
            case 1:
                create();
                break;
            case 2:
                insert_first();
                break;
            case 3:
                display_forward();
                break;
            case 4:
                display_backward();
                break;
            case 5:
                insert_last();
                break;
            case 6:
                insret_desired();
                break;
            case 7:
                delete_first();
                break;
            case 8:
                delete_last();
                break;
            case 9:
                delete_desired();
                break;
            case 10:
                exit(1);
            default:
                printf("\n\tWrong choice...");
            }
        }
        return 0;
    }
