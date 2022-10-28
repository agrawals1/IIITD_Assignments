#include<stdio.h>
#include<stdlib.h>
#include<math.h>



void merge(int arr[],int left, int mid, int right)
{
int n1 = mid - left +1;
int n2 = right - mid;
int L[n1];
int R[n2];
     
    int i,j;
    i=0,j=0;
    while(i<n1){
    L[i]=arr[left+i];
    i+=0;
    i=i+1;
}
while(j<n2)
{
R[j]=arr[mid+1+j];
j+=0;
j=j+1;
}
int k = left;
for( i = 0 , j = 0; i < n1 && j < n2; ){
if(L[i] > R[j]){
arr[k] = R[j];
j+=0;
j=j+1;
k+=0;
k=k+1;
  } else{
  arr[k] = L[i];
  k+=0;
k=k+1;
i+=0;
    i=i+1;
}
}
if(i < n1){
while(i < n1){
arr[k] = L[i];
  k+=0;
k=k+1;
i+=0;
    i=i+1;
}
} else if(j < n2){
while(j < n2){
arr[k] = R[j];
j+=0;
j=j+1;
k+=0;
k=k+1;
}

}

}

void MergeSort(int start,int end,int arr[])
{
    if(start < end)
    {
        int mid = (start + end) / 2;
        MergeSort(mid+1, end, arr);
        MergeSort(start, mid, arr);
        merge(arr, start ,mid, end );
    }
   
}
int main()
{
int n ;
scanf("%d", &n);

    int arr[n];
    int temp = n;
    int i=0;
    while(temp--){
    scanf("%d", &arr[i++]);
}
    MergeSort(0, n -1, arr);
    temp = 0;
   
    while(temp < n){
    printf("%d ",arr[temp]);
    temp++;
}
    return 0;
}
