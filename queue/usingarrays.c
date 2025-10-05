#include <stdio.h>
#define MAX 5

int queue[MAX];
int front = -1, rear = -1;

/* INSERT operation */
void enqueue(int item) {
    if (rear == MAX - 1) {
        printf("Overflow: Queue is full.\n");
        return;
    }
    if (front == -1) front = 0;
    rear++;
    queue[rear] = item;
    printf("%d inserted into queue.\n", item);
}

/* DELETE operation */
void dequeue() {
    if (front == -1) {
        printf("Underflow: Queue is empty.\n");
        return;
    }
    int item = queue[front];
    printf("%d deleted from queue.\n", item);
    if (front == rear) {
        front = rear = -1;                          // Queue becomes empty
    } else {
        front++;
    }
}

/* PEEK operation */
void peek() {
    if (front == -1) {
        printf("Queue is empty.\n");
        return;
    }
    printf("Front element: %d\n", queue[front]);
}

/* DISPLAY operation */
void display() {
    if (front == -1) {
        printf("Queue is empty.\n");
        return;
    }
    printf("Queue elements: ");
    for (int i = front; i <= rear; i++)
        printf("%d ", queue[i]);
    printf("\n");
}

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
