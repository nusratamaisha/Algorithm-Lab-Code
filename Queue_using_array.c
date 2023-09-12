#include<stdio.h>

int queue[10];
int front=-1,rear=-1;

void enqueue(int num){
    if(rear == 9){
        printf("overflow.\n");
    }
    else if(front == -1 && rear == -1){
        front = 0;
        rear = 0;
        queue[rear] = num;
    }
    else{
        queue[++rear] = num;
    }


}



void dequeue(){
    int first;
    if(front == -1 && rear == -1){
        printf("underflow.\n");
    }

    else if(front == rear){
        front = -1;
        rear = -1;
    }
    else{
        front++;
    }
}


int peak(){
    return queue[rear];
}



void display(){
    int i;
    if(front == -1 && rear == -1){
        printf("the queue is empty.\n");
    }
    else{
        printf("Queue values are:\n");
        for(i=front; i<=rear; i++){
            printf("%d\n",queue[i]);
        }
    }

}



int isEmpty(){
    if(front == -1 && rear ==-1){
        return 1;
    }
    else{
        return 0;
    }
}



int isFull(){
    if(rear == 9){
        return 1;
    }

    else{
        return 0;
    }
}



int main(){
    printf("0.EXIT\n1.Enqueue\n2.Dequeue\n3.Display\n4.Weather the queue is full\n5.Weather the queue is empty\n6.Peak value\n");

    int option,num,full,empty;

    while(1){
        printf("Enter operation number:");
        scanf("%d",&option);
        switch(option){
            case 0:
            break;

            case 1:
            {
                printf("Enter value to Queue:");
                scanf("%d",&num);
                enqueue(num);
                break;
            }

            case 2:
            {
                dequeue();
                display();
                break;
            }


            case 3:
            {
                display();
                break;
            }

            case 4:
            {
                full = isFull();
                if(full == 1){
                    printf("the queue is full.\n");
                }
                else{
                    printf("the queue is not full.\n");
                }
                break;
            }

            case 5:
            {
                empty = isEmpty();
                if(empty == 1){
                    printf("the queue is empty.\n");
                }
                else{
                    printf("the queue is not empty.\n");
                }
                break;
            }

            case 6:
                printf("peak value is: %d\n",peak());
                break;

            default:
            printf("invalid option.");
        }
        if(option == 0){
            break;
        }
    }
}

