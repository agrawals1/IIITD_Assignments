#include<stdio.h>
#include<stdlib.h>

void triples(int *arr,int n)
{
    

    for(int i=0;i<n-1;i++)
    {
        for(int j=0;j<n-i-1;j++)
        {
            if(arr[j]>arr[j+1])
            {
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
        
    }

   


    int trip_found = 0;
    for(int i=0;i<n;i++)
    {
        int end = n-1;
        int start = i+1;
        int piv = arr[i];
        while(start<end)
        {
            if(piv+arr[start]+arr[end]==0)
            {
                printf("%d %d %d\n",piv, arr[start], arr[end]);
                start++;
                end--;
                trip_found = 1;
            }
            else if(piv + arr[start]+arr[end]<0)
            {
                start++;
            }
            else
            {
                end--;
            }
        }
    }
    if(!trip_found)
    {
        printf("not found");
    }
}

int main()
{
    int n ;
    printf("enter the number of elements");
    scanf("%d", &n);
    printf("enter array elements");
    int *arr = (int*)malloc(sizeof(int)*n);
    for(int i=0;i<n;i++)
    {
        scanf("%d", &arr[i]);
    }
    
    triples(arr, n);
}