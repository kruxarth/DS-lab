#include <stdio.h>
#define SIZE 5   // maximum size of the queue

int queue[SIZE];
int front = -1, rear = -1;

// Check if queue is full
int isFull() {
    return ((rear + 1) % SIZE == front);
}

// Check if queue is empty
int isEmpty() {
    return (front == -1);
}

// Insert element into circular queue
void enqueue(int x) {
    if (isFull()) {
        printf("Queue is full!\n");
        return;
    }
    if (front == -1) front = 0;  // first element
    rear = (rear + 1) % SIZE;
    queue[rear] = x;
    printf("%d enqueued\n", x);
}

// Delete element from circular queue
int dequeue() {
    if (isEmpty()) {
        printf("Queue is empty!\n");
        return -1;
    }
    int val = queue[front];
    if (front == rear) {
        // queue becomes empty
        front = rear = -1;
    } else {
        front = (front + 1) % SIZE;
    }
    return val;
}

// Display the queue
void display() {
    if (isEmpty()) {
        printf("Queue is empty!\n");
        return;
    }
    printf("Queue: ");
    int i = front;
    while (1) {
        printf("%d ", queue[i]);
        if (i == rear) break;
        i = (i + 1) % SIZE;
    }
    printf("\n");
}

int main() {
    enqueue(10);
    enqueue(20);
    enqueue(30);
    enqueue(40);
    display();

    printf("Dequeued: %d\n", dequeue());
    display();

    enqueue(50);
    enqueue(60);  // fills circularly
    display();

    return 0;
}
