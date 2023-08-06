#include<iostream>
using namespace std;
struct Node
{
    int data;
    struct Node *next;
};

struct Node *head = NULL;

void push()
{
    Node *new_node = new Node();
    cout<<"Enter data: ";
    cin>>new_node -> data;
    new_node -> next = head;
    head = new_node;
}

void pop()
{
    if(head == NULL){
        cout<<"the stack is empty.";
    }
    Node* nextNode = head->next;
    head->data = nextNode->data;
    head->next = nextNode->next;
    delete nextNode;
}


void display()
{
    struct Node *temp;
    if(head == NULL)
    {
        cout<<"the stack is empty";
        return;

    }
    else
    {
        temp = head;
        while(temp != NULL)
        {
            cout<<temp -> data<<endl;
            temp = temp -> next;
        }
    }
    cout<<" "<<endl;
}
int main()
{

    push();
    //display();

    push();
    //display();


    push();
    //display();


    push();
    display();

    pop();
    //display();

    pop();
    display();

    return 0;
}
