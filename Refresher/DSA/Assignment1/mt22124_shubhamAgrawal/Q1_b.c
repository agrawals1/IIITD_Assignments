#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int top_stack1 = -1;
int top_stack2 = -1;
int *rev_arr;
int pop(int arr[])
{
    return arr[top_stack1];
}

void push(int num)
{
    
    rev_arr[top_stack2] = num;
    printf("%d\n",rev_arr[top_stack2]);
}

void reverse_stack(int arr[], int n)
{
    top_stack1 = n-1;
    
    if(top_stack1 != -1)
    {
        int num = pop(arr);
        
        top_stack1--;
        top_stack2++;
        
        push(num);
        
        reverse_stack(arr, --n);
    }
    else
    {
        // int num = pop(arr);
        // push(num);
        // for(int i=0;i<n;i++)
        // {
        //     printf("%d\n", rev_arr[i]);
        // }
        return;
    }
}
int main()
{

    // int n=1, j=0, idx=0, idx_int=0;
    // char *char_arr = (char*)malloc(sizeof(char)*100);
    // char* token;
    // do
    // {
    //     char_arr[idx] = getchar();
    //     if(char_arr[idx] == ',')
    //     {
    //         n++;
    //     }
    //     if(idx == 100)
    //     {
    //         char_arr = realloc(char_arr, sizeof(char)*(100+idx));
    //     }
    //     idx++;

    // } while (char_arr[idx-1]!='\n');
    // int *arr = (int*)malloc(sizeof(int)*n);
    // int *rev_arr = (int*)malloc(sizeof(int)*n);
    // while(token = strtok_r(char_arr, " , ", &char_arr))
    // {
    //     arr[idx_int++] = atoi(token);
    // }
    // printf("hiiiiii");
    int n;
    printf("enter no. of elements");
    scanf("%d", &n);
    int *arr = (int*)malloc(sizeof(int)*n);
    rev_arr = (int*)malloc(sizeof(int)*n);
    printf("enter stack elements");
    for(int i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
    reverse_stack(arr, n);
    
    return 0;
}