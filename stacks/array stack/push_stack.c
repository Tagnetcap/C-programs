#include <stdio.h>
#define MAX 10                       //size of stack (let 10)

    int top = -1;                   //top of stack(empty initially)   
    int stack [MAX];

void push(int val , int n){
                    
    if (top == n)
        printf("overflow");
    else
    {
        top++;
        stack [top] = val;
    }
}

int main(){
    int v = 10;                         //value to push
    int n = MAX;                         //size of stack
    push (v , n);
}

