#include <stdio.h>

int insertelement (int arr[] , int N , int pos , int item){
    int i;

    for(i=N-1 ; i >= pos ; i--){
      arr[i+1] = arr [i];
    }

    arr[pos] = item ;
    N=N+1;
    return N;
}
int main(){

    int arr[] = {10,20,15,8,9};
    int item = 30;
    int n = sizeof(arr) / sizeof(arr[0]);
    int pos = 2 ;

    n = insertelement(arr,n,pos,item);

    printf("Array after insertion: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);}

    }
