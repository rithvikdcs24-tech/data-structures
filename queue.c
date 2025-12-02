#include <stdio.h>
#define SIZE 5

int queue[SIZE];
int front = -1, rear = -1;

// Check if queue is empty
int isEmpty() {
    return (front == -1);
}

// Check if queue is full
int isFull() {
    return ((rear + 1) % SIZE == front);
}

// Add item
void enqueue(int value) {
    if (isFull()) {
        printf("Queue is Full!\n");
        return;
    }

    if (isEmpty()) {
        front = rear = 0;
    } else {
        rear = (rear + 1) % SIZE;
    }

    queue[rear] = value;
   // printf("Enqueued %d\n", value);
}

// Remove item
void dequeue() {
    if (isEmpty()) {
        printf("Queue is Empty!\n");
        return;
    }

    printf("Dequeued %d\n", queue[front]);

    if (front == rear) {
        front = rear = -1; // now empty
    } else {
        front = (front + 1) % SIZE;
    }
}

// Display items
void display() {
    if (isEmpty()) {
        printf("Queue is Empty!\n");
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
    int choice, val;
    while (1) {
        printf("\n1. Enqueue\n2. Dequeue\n3. Display\n4. Exit\nChoose: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value: ");
                scanf("%d", &val);
                enqueue(val);
                display();
                break;
            case 2:
                dequeue();
                display();
                break;
            case 3:
                display();
                break;
            case 4:
                return 0;
            default:
                printf("Invalid!\n");
        }
    }
}
