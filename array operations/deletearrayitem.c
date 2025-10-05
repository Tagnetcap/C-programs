#include <stdio.h>

int delete_element(int arr[] , int *n , int pos ){

    int item ; 
    item = arr [pos] ; 
    for (int i = pos ; i <= *n - 2 ; i++){
        arr[i] = arr[i+1];
    }
    (*n)--;
}
int main(){
    int arr [] = {10,20,15,8,9};
    int pos = 2;
    int n = sizeof(arr) / sizeof(arr[0]);

    delete_element(arr , &n , pos);

    printf("Array after deletion: ");
    for (int i = 0; i < n; i++) {  
        printf("%d ", arr[i]);
}

}