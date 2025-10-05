#include <stdio.h>

int search (int a [], int pos , int n){
   int item = a [pos] ; 
   for (int i=0 ; i < n-1 ; i++)
   {
    if (a[i] = a[pos])
        {
            return pos;
        }
   }
}


int main (){
    int a[] = {10,20,15,8,9};
    int pos = 2 ;
    int n = sizeof(a) / sizeof(a[0]) ;

    search (a , pos , n);
    printf("%d \n", pos);
}
