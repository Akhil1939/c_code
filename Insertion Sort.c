#include<stdio.h>
#include<conio.h>
int main()
{
    int arr[50], size, i, j, k, element, index;
    printf("Enter Array Size: ");
    scanf("%d", &size);
    printf("Enter %d Array Elements: ", size);
    for(i=0; i<size; i++)
        scanf("%d", &arr[i]);
    for(i=1; i<size; i++)
    {
        element = arr[i];
        if(element<arr[i-1])
        {
            for(j=0; j<=i; j++)
            {
                if(element<arr[j])
                {
                    index = j;
                    for(k=i; k>j; k--)
                        arr[k] = arr[k-1];
                    break;
                }
            }
        }
        else
            continue;
        arr[index] = element;
    }
    printf("\nSorted Array:\n");
    for(i=0; i<size; i++)
        printf("%d ", arr[i]);
    getch();
    return 0;
}
