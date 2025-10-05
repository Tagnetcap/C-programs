#include <stdio.h>
#include <stdlib.h>

/* Define Node structure */
typedef struct Node {
    int data;
    struct Node *next;
} Node;

/* Global pointers */
Node *front = NULL;
Node *rear = NULL;

/* ENQUEUE - Insert at end */
void enqueue(int item) {
    Node *ptr = (Node*)malloc(sizeof(Node));
    if (ptr == NULL) {
        printf("Overflow: Memory not available.\n");
        return;
    }
    ptr->data = item;
    ptr->next = NULL;

    if (front == NULL) {
        front = rear = ptr;
    } else {
        rear->next = ptr;
        rear = ptr;
    }
    printf("%d inserted into queue.\n", item);
}

/* DEQUEUE - Delete from front */
void dequeue() {
    if (front == NULL) {
        printf("Underflow: Queue is empty.\n");
        return;
    }

    Node *ptr = front;
    int item = ptr->data;
    front = front->next;

    if (front == NULL)  // Queue becomes empty
        rear = NULL;

    free(ptr);
    printf("%d deleted from queue.\n", item);
}

/* PEEK - Display front element */
void peek() {
    if (front == NULL) {
        printf("Queue is empty.\n");
        return;
    }
    printf("Front element: %d\n", front->data);
}

/* DISPLAY - Print all elements */
void display() {
    if (front == NULL) {
        printf("Queue is empty.\n");
        return;
    }
    Node *ptr = front;
    printf("Queue elements: ");
    while (ptr != NULL) {
        printf("%d ", ptr->data);
        ptr = ptr->next;
    }
    printf("\n");
}

/* MAIN FUNCTION */
int main() {
    enqueue(10);
    enqueue(20);
    enqueue(30);
    display();
    peek();
    dequeue();
    display();
    dequeue();
    dequeue();
    dequeue();
    return 0;
}
