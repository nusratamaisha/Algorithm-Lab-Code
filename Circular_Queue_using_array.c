#include <stdio.h>
#define SIZE 5

int front = -1, rear = -1;
int queue[SIZE];

void enqueue(int num) {
    if ((rear + 1) % SIZE == front) {
        printf("Overflow\n");
    } else if (front == -1 && rear == -1) {
        front = 0;
        rear = 0;
        queue[rear] = num;
    } else {
        rear = (rear + 1) % SIZE;
        queue[rear] = num;
    }
}

void dequeue() {
    if (front == -1) {
        printf("Underflow\n");
    } else if (front == rear) {
        front = -1;
        rear = -1;
    } else {
        front = (front + 1) % SIZE;
    }
}

int isFull() {
    if ((front == 0 && rear == SIZE - 1) || (front == (rear + 1) % SIZE)) {
        return 1;
    } else {
        return 0;
    }
}

int isEmpty() {
    if (front == -1 && rear == -1) {
        return 1;
    } else {
        return 0;
    }
}

void display() {
    int i ;
    if (isEmpty()) {
        printf("Queue is empty.\n");
    }
    else if(front <= rear){
        for(i=front; i<=rear; i++){
            printf("%d ",queue[i]);
        }
    }
    else if(front>rear){
        for(i=0; i<=rear;i++){
            printf("%d ",queue[i]);
        }
        for(i=front; i<SIZE; i++){
            printf("%d ",queue[i]);
        }
    }

}

int main() {
    printf("0. EXIT\n1. Enqueue\n2. Dequeue\n3. Display\n4. Check if the queue is full\n5. Check if the queue is empty\n");

    int option, num, full, empty;

    while (1) {
        printf("Enter operation number: ");
        scanf("%d", &option);
        switch (option) {
            case 0:
                return 0;

            case 1:
                printf("Enter value to enqueue: ");
                scanf("%d", &num);
                enqueue(num);
                break;

            case 2:
                dequeue();
                break;

            case 3:
                display();
                break;

            case 4:
                full = isFull();
                if (full == 1) {
                    printf("The queue is full.\n");
                } else {
                    printf("The queue is not full.\n");
                }
                break;

            case 5:
                empty = isEmpty();
                if (empty == 1) {
                    printf("The queue is empty.\n");
                } else {
                    printf("The queue is not empty.\n");
                }
                break;

            default:
                printf("Invalid option.\n");
        }
    }
}
