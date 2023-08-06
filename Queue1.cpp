#include<iostream>
using namespace std;

struct Node{
    int data;
    Node *next;
};

struct Node *head = NULL;

void enter_queue(){
    Node *new_node = new Node();
    cout<<"Enter data: ";
    cin>>new_node -> data;
    new_node -> next = NULL;
    if(head == NULL){
        head = new_node;
    }
    else{
        Node *temp=head;
        while(temp -> next != NULL){
            temp = temp -> next;
        }
        temp -> next = new_node;
    }
}


void delete_queue(){
    if(head == NULL){
        cout<<"the queue is empty.";
    }
    Node* nextNode = head->next;
    head->data = nextNode->data;
    head->next = nextNode->next;
    delete nextNode;
}


void print_queue()
{
    struct Node *temp;
    if(head == NULL)
    {
        cout<<"the queue is empty";
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

int main(){
    enter_queue();
    enter_queue();
    enter_queue();
    enter_queue();
    enter_queue();
    enter_queue();
    print_queue();
    delete_queue();
    delete_queue();
    print_queue();
}
