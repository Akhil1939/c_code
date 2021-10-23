#include<stdio.h>
#include<conio.h>

int BS(int [], int ,int ,int );
void tower(int , char , char , char );

int main()
{
    int n,a[50],key,opn,i,pos;
    do
    {

        printf(" \n\n Press 1 -> Binary Search , 2-> Towers of Hanoi 3-> Quit\n");
        scanf("%d",&opn);
        switch(opn)
        {

        case 1:
            printf(" How Many Elements ? ");
            scanf("%d",&n);
            printf(" Read all the elements is ASC order ::\n");

            for(i=1;i<=n;i++)
                scanf("%d",&a[i]);
            printf(" Read the Key (Search) Element :: ");
            scanf("%d",&key);
            pos=BS(a,key,1,n);

            if(pos)
                printf(" Success: %d found at %d \n", key,pos);
            else
             printf(" Falure: %d Not found in the list ! \n",key);
            break;

        case 2:
            printf("\n\n How Many Disks ?");
            scanf("%d", &n);
            printf("\n\n Result of Towers of Hanoi for %d Disks \n",n);

            tower(n,'A','B','C');

            printf("\n\n Note: A-> Source, B-> Intermediate, C-> Destination\n");
            break;

        case 3:
            printf(" Terminating \n");
            break;
        default:
            printf(" Invalid Option !! Try Again !! \n");
        }

        printf(" Press a Key. . . ");
        getch();

    }while(opn != 3);

    return 0;
}
int BS(int a[], int key,int low,int high)
{
    int mid;

    if(low > high)
        return 0; /* failure */
    else
    {
        mid=(low+high)/2;
        if(a[mid]== key)
            return mid; /* Success */
        if(key < a[mid])
          return(BS(a,key,low,mid-1));
        return(BS(a,key,mid+1,high));
    }
}
void tower(int n, char src, char intr, char dst)
{
    if(n > 0)
    {
        tower(n-1,src,dst,intr);

        printf("Move disk %d from %c to %c \n", n,src,dst);

        tower(n-1,intr,src,dst);
    }
}
