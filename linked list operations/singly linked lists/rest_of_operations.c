#include <stdio.h>
#include <stdlib.h>

#define MAX_NODES 10   // Total preallocated nodes

/* Node structure */
typedef struct Node {
    int info;
    struct Node *link;
} Node;

/* Global pointers */
Node *START = NULL;   // Points to first node of main list
Node *AVAIL = NULL;   // Points to first node of free list

/* Step 1: Initialize AVAIL list (pool of free nodes) */
void initialize_avail() {
    static Node nodes[MAX_NODES];  // static → memory persists
    for (int i = 0; i < MAX_NODES - 1; i++) {
        nodes[i].link = &nodes[i + 1];
    }
    nodes[MAX_NODES - 1].link = NULL;
    AVAIL = &nodes[0];
}

/* Step 2: Get a free node from AVAIL list */
Node* get_node() {
    if (AVAIL == NULL) {
        printf("Overflow: No free nodes available.\n");
        exit(0);
    }
    Node *ptr = AVAIL;       // Take first free node
    AVAIL = AVAIL->link;     // Move AVAIL to next free node
    ptr->link = NULL;        // Clear its link
    return ptr;
}

/* Step 3: Return a node back to AVAIL list */
void free_node(Node *ptr) {
    ptr->link = AVAIL;   // Link deleted node back to AVAIL
    AVAIL = ptr;         // Move AVAIL to point to this node
}

/* Step 4: Insert at beginning */
void insert_begin(int item) {
    Node *ptr = get_node();
    ptr->info = item;
    ptr->link = START;   // Link new node to previous start
    START = ptr;         // Update START
    printf("%d inserted at beginning.\n", item);
}

/* Step 5: Insert at end */
void insert_end(int item) {
    Node *ptr = get_node();
    ptr->info = item;
    ptr->link = NULL;

    if (START == NULL) {
        START = ptr;
    } else {
        Node *temp = START;
        while (temp->link != NULL)
            temp = temp->link;
        temp->link = ptr;
    }
    printf("%d inserted at end.\n", item);
}

/* Step 6: Delete from beginning */
void delete_begin() {
    if (START == NULL) {
        printf("Underflow: List is empty.\n");
        return;
    }

    Node *ptr = START;
    int item = ptr->info;
    START = START->link;
    free_node(ptr);
    printf("%d deleted from beginning.\n", item);
}

/* Step 7: Delete from end */
void delete_end() {
    if (START == NULL) {
        printf("Underflow: List is empty.\n");
        return;
    }

    Node *ptr = START;
    Node *prev = NULL;

    // Traverse to last node
    while (ptr->link != NULL) {
        prev = ptr;
        ptr = ptr->link;
    }

    int item = ptr->info;

    if (prev == NULL)
        START = NULL;        // Only one node
    else
        prev->link = NULL;   // Disconnect last node

    free_node(ptr);
    printf("%d deleted from end.\n", item);
}

/* Step 8: Traverse the list */
void traverse_list() {
    if (START == NULL) {
        printf("List is empty.\n");
        return;
    }

    Node *ptr = START;
    printf("List elements: ");
    while (ptr != NULL) {
        printf("%d ", ptr->info);
        ptr = ptr->link;
    }
    printf("\n");
}

/* Step 9: Display the AVAIL list */
void display_avail() {
    Node *ptr = AVAIL;
    printf("AVAIL list nodes: ");
    while (ptr != NULL) {
        printf("[%p] -> ", (void*)ptr);
        ptr = ptr->link;
    }
    printf("NULL\n");
}

/* MAIN FUNCTION */
int main() {
    initialize_avail();  // Prepare the available node pool

    insert_begin(10);
    insert_begin(5);
    insert_end(20);
    insert_end(30);
    traverse_list();

    delete_begin();
    traverse_list();

    delete_end();
    traverse_list();

    printf("\nCurrent AVAIL list:\n");
    display_avail();

    return 0;
}
