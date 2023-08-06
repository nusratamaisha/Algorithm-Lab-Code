#include<iostream>
#include <cstdlib>
using namespace std;
struct Node{
    int data;
    Node *next;
};



void print_list(Node *head){
    Node *temp = head;
    while(temp!=NULL){
        cout<<temp -> data<<" ";
        temp =temp -> next;
    }
    cout<<endl;
}



Node* insert_at_begin(Node *head,int n){
    Node *new_node = new Node();
    new_node -> data = n;
    new_node -> next = head;
    head = new_node;
    return head;
}



Node* insert_end(Node *head,int n){
    Node *new_node = new Node();
    new_node -> data = n;
    new_node -> next =NULL;

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
    return head;
}




Node* insert_position(Node *head,int n,int pos){
    Node *new_node = new Node();
    new_node -> data = n;

    if(pos == 1){
        new_node -> next = head;
        head = new_node;
    }
    else{
        Node *temp = head;

        for(int i = 1; i < pos - 1 && temp != NULL; i++){
            temp = temp -> next;
        }

        if(temp == NULL){
            cout<<"invalid position"<<endl;
        }

        else{
            new_node -> next = temp -> next;
            temp -> next = new_node;
        }

    }
    return head;
}




void update_by_value(Node* head,int old_value,int new_value){
    Node *temp = head;
    if(temp == NULL){
        cout<<"the linked list is not initialized."<<endl;
    }
    else{
        while(temp != NULL){
            if(temp -> data == old_value){
                temp -> data = new_value;
            }
            temp=temp->next;
        }
    }
}



void update_by_position(Node *head,int num,int position){

    if(position == 1){
        head -> data = num;
    }
    else{
        Node *temp = head;

        for(int i = 1; i < position && temp != NULL; i++){
            temp = temp -> next;
        }

        if(temp == NULL){
            cout<<"invalid position"<<endl;
        }

        else{
            temp -> data = num;
        }

    }
}




void delete_from_begin(Node* head) {
    if(head == NULL){
        cout<<"the list is empty.";
    }
    Node* nextNode = head->next;
    head->data = nextNode->data;
    head->next = nextNode->next;
    delete nextNode;
}



void delete_by_value(Node* head, int num) {
    Node* temp = head;
    if(head -> data == num){
        delete_from_begin(head);
    }
    while (temp != NULL) {
        if (temp->next != NULL && temp->next->data == num) {
            Node* nextNode = temp->next;
            temp->next = nextNode->next;
            delete nextNode;
        }
        temp = temp->next;
    }
}



void delete_by_position(Node *head,int position){
    if(position == 1){
        delete_from_begin(head);
    }
    else{
        Node *temp = head;

        for(int i = 1; i < position-1 && temp != NULL; i++){
            temp = temp -> next;
        }

        if(temp == NULL){
            cout<<"invalid position"<<endl;
        }

        else{
            Node* nextNode = temp->next;
            temp->next = nextNode->next;
            delete nextNode;
        }

    }
}



int main(){
    Node *head;
    head = new Node();
    head -> data = 19;

    print_list(head);

    head = insert_at_begin(head,5);
    print_list(head);

    head = insert_end(head,50);
    print_list(head);

    head =  insert_position(head,11,2);
    print_list(head);

    head =  insert_position(head,20,3);
    print_list(head);

    update_by_value(head,5,2);
    print_list(head);

    update_by_position(head,7,4);
    print_list(head);

    delete_from_begin(head);
    print_list(head);

    delete_by_value(head,19);
    print_list(head);

    delete_by_position(head,2);
    print_list(head);

}
