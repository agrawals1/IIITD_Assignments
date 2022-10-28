#include<stdio.h>
#include<stdlib.h>

int mountainTop(int *arr, int start, int end, int n)
{
    int mid = start + (end-start)/2;

    if((mid==0 || arr[mid-1] <= arr[mid]))
    {
        if((mid == n - 1 || arr[mid + 1] <= arr[mid]))
        {
            return mid;
        }
    }
    

    else if(mid > 0 && arr[mid - 1] > arr[mid])
    {
        return mountainTop(arr, mid+1, end,n);
    }

    else
    {
        return mountainTop(arr, mid + 1, end, n);
    }
    

}

int main()
{
    int n;
    printf("enter number of elements");
    scanf("%d",&n);
    while(n<3)
    {
        printf("too few numbers");
    }
    
    int arr[n];
    printf("enter array elements");
    for(int i=0;i<n;i++)
    {
        scanf("%d", &arr[i]);
    }
    int peak = mountainTop(arr, 0, n-1, n);
    printf("%d", peak);
}