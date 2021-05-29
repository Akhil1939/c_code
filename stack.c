#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<malloc.h>

struct stack
{
    int data;
    struct stack *ptr;
};

struct stack *top=NULL,*temp;

void push(int x)
{
    if(top==NULL)
    {
        top=(struct stack *)malloc(sizeof (struct stack));
        top->data=x;
        top->ptr=NULL;
    }
    else{
        temp=(struct stack *)malloc(sizeof(struct stack));
        temp->data=x;
        temp->ptr=top;
        top=temp;
    }
}
int pop()
{
    int x;
    if(top==NULL)
    {
        printf("\n stack is empty ");
        return (-1);
    }
    else{
        temp=top;
        x=top->data;
        top=top->ptr;
        free(temp);
        return(x);
    }
}
void display()
{
    if(top==NULL)
    {
        printf("\n stack is empty");
    }
    else{
        temp=top;
        for(temp=top;temp!=NULL;temp=temp->ptr)
        {
            printf("\n %d",temp->data);
        }
    }
}
void main()
{
    int ch,x;
    while(1)
    {
            printf("\n 1. push");
            printf("\n 2. pop");
            printf("\n 3. display");
            printf("\n 4. exit");
            printf("\n enter your choice:");
            scanf("%d",ch);

            switch(ch)
            {
            case 1:
                printf("\n enter element to push : ");
                scanf("%d",&x);
                push(x);
                getch();
                break;
            case 2:
                x=pop();
                printf("\n the poped element  %d",x);
                getch();
                break;
            case 3:
                display();
                getch();
                break;
            case 4:
                exit(0);
            default:
                printf("\n invalid choice:");
                getch();
            }
    }
}
