#include <stdio.h>

#define MAX 10
struct node {
    int info;
    struct node *link;
};

struct node nodes[MAX];             // Preallocated memory (simulates memory)
struct node *START = NULL;          // Head of main linked list
struct node *AVAIL = NULL;          // Head of available list

void initialize() {
    for (int i = 0; i < MAX - 1; i++) {
        nodes[i].link = &nodes[i + 1];
    }
    nodes[MAX - 1].link = NULL;
    AVAIL = &nodes[0];
}

struct node* getnode() {
    if (AVAIL == NULL) {
        printf("Overflow: No free nodes available\n");
        return NULL;
    }
    struct node *PTR = AVAIL;      // Take first free node
    AVAIL = AVAIL->link;           // Move AVAIL to next free node
    return PTR;
}

void traverse() {
    struct node *PTR = START;
    if (PTR == NULL) {
        printf("List is empty\n");
        return;
    }

    printf("List: ");
    while (PTR != NULL) {
        printf("%d -> ", PTR->info);
        PTR = PTR->link;
    }
    printf("NULL\n");
}

void insert(int data) {
    struct node *new_node = getnode();
    if (new_node == NULL) {
        printf("No memory available\n");
        return;
    }
    new_node->info = data;
    new_node->link = START;
    START = new_node;
}


int main(){

    initialize();

    insert(10);
    insert(20);
    insert(30);
    
    traverse();
    return 0;
}