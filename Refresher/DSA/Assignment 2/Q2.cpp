using namespace std;
#include <iostream>
#include <bits/stdc++.h>

void MaxWindow(int arr[], int n, int k)
{
    std::deque<int> dq(k);
    int i = 0;
    if(!n)
    {
        printf("no elements entered");
        return;
    }
    if(k>=n)
    {
        k = n;
    }
    for (; i < k; i++)
    {        
        
        while ((!dq.empty()) && arr[i] >= arr[dq.back()])
        dq.pop_back();
        
        dq.push_back(i);
        
        
    }
     for (; i < n; i++)
    {
        cout << arr[dq.front()] << " ";    

        while ((!dq.empty()) && arr[i] >= arr[dq.back()])
        dq.pop_back();
    
        while ((!dq.empty()) && dq.front() <= i - k)
        dq.pop_front();
        
    
    dq.push_back(i);
    
}
    cout << arr[dq.front()];
}

int main()
{
    int n,k;
    printf("enter the array size");
    scanf("%d", &n);
    printf("enter the window size");
    scanf("%d", &k);
    int *arr = (int*)malloc(n*sizeof(int));
    printf("enter the elements");
    for(int i=0;i<n;i++)
    {
        scanf("%d", &arr[i]);
    }
    MaxWindow(arr, n, k);
    return 0;
}