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

void search(struct bst *t)

{
    if((temp->data < t->data) && (t->left ==NULL))
    {
        t->left =temp;
    }
    else if ((temp->data < t->data ) && (t->left != NULL))
    {
        search(t->left);
    }
    if ((temp->data > t->data) && (t->right ==NULL))
    {
        t->right = temp;
    }
    else if ((temp->data > t->data) && (t->right != NULL))
    {
        search(t->right);
    }
}
 void insert()
 {
     createnode();

     if (root ==NULL)
        root=temp;
     else
        search(root);
 }

 void preorder(struct bst *t)
 {
     if (root ==NULL)
     {
         printf("\n no element in a tree to display");
     return;
     }

 printf("%d -->",t->data);

 if (t->left !=NULL)
    preorder(t->left);
 if (t->right !=NULL)
    preorder(t->right);
 }

 void postorder(struct bst *t)
 {
     if (root==NULL)
     {
         printf("\n no element in a tree to desplay ");
         return;
     }
     if (t->left != NULL)
        postorder(t->left);
     if(t->right !=NULL)
        postorder(t->right);
     printf("%d -->",t->data);
 }

void main()
          {
              int ch;
              while(1)
              {
                  printf("\n 1. INSERT AN ELEMENT INTO BINARY SEARCH TREE :");
                  printf("\n 2. PREORDER TRAVERSAL");
                  printf("\N 3. INORDER TRAVERSAL");
                  printf("\n 4. POST ORDER TRAVERSAL");
                  printf("\n 5. EXIT");

                  printf("\n ENTER YOUR CHOICE :");
                  scanf("%d",&ch);

                  switch (ch)
                  {
                  case 1:
                    insert();
                    getch();
                    break;
                  case 2:
                    preorder(root);
                    getch();
                    break;
                 case 3:
                    inorder(root);
                    getch();
                    break;
                  case 4:
                    postorder(root);
                    getch();
                    break;
                  case 5:
                    exit(0);
                  }


              }
          }
