#include<stdio.h>
#include<stdlib.h>

int mindays(int *arr,int req,int lim,int n)
{
    int max = 0;
    if(req*lim > n)
    return -1;
    for(int i=0;i<n;i++)
    {
        if(arr[i] >=max)
        max = arr[i];
    }
    int start=1, end=max, mid;
    while(start<end)
    {
        
        mid = (start+end)/2;
        int frame = 0;
        int window = 0;
        for(int i=0;i<n;i++)
        {
            if(arr[i]>mid)
            {
                frame = 0;
            }
            else
            {
                frame++;
            }
            if(frame>=lim)
            {
                frame = 0;
                window++;
            }
            if(window == req)
            break;
            
        }
        if(window==req)
        {
            end--;
        }
        else
        {
            start++;
            
        }
    }
    return start;
}

int main()
{
    int n;
    int limit;
    int req;
    printf("enter no. of frames");
    scanf("%d", &n);
    int *buildays = (int*)malloc(sizeof(int)*n);
    printf("enter build days");
    for(int i=0;i<n;i++)
    {
        scanf("%d", &buildays[i]);
    
    }
    printf("enter limit");
    scanf("%d", &limit);
    printf("enter requirement");
    scanf("%d", &req);
    
    int days = mindays(buildays, req, limit, n);
    printf("%d", days);
}