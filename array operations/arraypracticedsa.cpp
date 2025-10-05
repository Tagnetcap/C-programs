#include <stdio.h>

int traversearray(int array[],int size) {

    int i;
    for (i=0 ; i < size ; i++) {
        printf( "%d \n" ,array[i]);
    }
      
};

int main(){

    int array[] =  {10 , 20 , 15 , 18 , 9 } ;

    int n = sizeof(array) / sizeof(array[0]) ;

    traversearray( array, n );

};