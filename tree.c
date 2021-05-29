#include<stdio.h>
#include<stdlib.h>

struct bst
{
    struct bst *left;
    int data;
    struct bst *right;
};

struct bst *root=NULL,*temp=NULL;
void createnode()
{
    int x;
    printf("\n enter data of node to be inserted :");
    scanf("%d",&x);
    temp=(struct bst *)malloc(sizeof(struct bst));
    temp->data=x;
    temp->left=NULL;
    temp->right=NULL;

}
