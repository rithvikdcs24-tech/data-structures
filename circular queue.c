#include <stdio.h>
#define MAX 5   // Maximum size of circular queue

int queue[MAX];
int front = -1, rear = -1;

// Function to insert an element
void insert() {
    int item;

    // Check for overflow
    if ((front == 0 && rear == MAX - 1) || (rear + 1 == front)) {
        printf("Queue Overflow! Cannot insert.\n");
        return;
    }

    printf("Enter element to insert: ");
    scanf("%d", &item);

    if (front == -1) {   // First element
        front = rear = 0;
    } else {
        rear = (rear + 1) % MAX;
    }

    queue[rear] = item;
    printf("Inserted %d\n", item);
}

// Function to delete an element
void delete() {
    if (front == -1) {
        printf("Queue Underflow! Nothing to delete.\n");
        return;
    }

    printf("Deleted element: %d\n", queue[front]);

    if (front == rear) {  // Only one element was present
        front = rear = -1;
    } else {
        front = (front + 1) % MAX;
    }
}

// Function to display queue elements
void display() {
    if (front == -1) {
        printf("Queue is Empty.\n");
        return;
    }

    printf("Queue elements: ");

    int i = front;
    while (1) {
        printf("%d ", queue[i]);
        if (i == rear)
            break;
        i = (i + 1) % MAX;
    }
    printf("\n");
}

int main() {
    int choice;

    while (1) {
        printf("\n--- Circular Queue Menu ---\n");
        printf("1. Insert\n");
        printf("2. Delete\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: insert();  break;
            case 2: delete();  break;
            case 3: display(); break;
            case 4: return 0;
            default: printf("Invalid choice! Try again.\n");
        }
    }
}
