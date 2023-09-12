#include<stdio.h>
#include<stdbool.h>

int stack[10];
int top = -1;

void push(int num){
    if(top == 9){
        printf("Overflow.\n");
    }
    else{
        stack[++top]=num;
    }
}

void pop(){
    if(top>=0){
        top--;
    }
    else if(top == -1){
        printf("UnderFlow.\n");
    }
}

int peak(){
    return stack[top];
}
void display(){
    int i;
    printf("stack values are:\n");
    for(i=top; i>=0; i--){
        printf("%d\n",stack[i]);
    }
}
int isEmpty(){
    if(top == -1){
        return 1;
    }
    else{
        return 0;
    }
}
int isFull(){
    if(top == 9){
        return 1;
    }
    else{
        return 0;
    }
}

int main(){
    printf("0.EXIT\n1.Push\n2.Pop\n3.Display\n4.Weather the stack is full\n5.Weather the stack is empty\n6.Peak value\n");

    int option,num,full,empty;

    while(true){
        printf("Enter operation number:");
        scanf("%d",&option);
        switch(option){
            case 0:
            break;

            case 1:
            {
                printf("Enter value to push:");
                scanf("%d",&num);
                push(num);
                break;
            }

            case 2:
            {
                pop();
                printf("After popping ");
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
                    printf("the stack is full.\n");
                }
                else{
                    printf("the stack is not full.\n");
                }
                break;
            }

            case 5:
            {
                empty = isEmpty();
                if(empty == 1){
                    printf("the stack is empty.\n");
                }
                else{
                    printf("the stack is not empty.\n");
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
