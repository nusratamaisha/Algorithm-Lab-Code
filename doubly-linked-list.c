
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
};

struct Node* head = NULL;

void print_list(struct Node* head) {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

struct Node* insert_at_begin(struct Node* head) {
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    printf("Enter data for the first position: ");
    scanf("%d", &new_node->data);
    new_node->next = head;
    new_node->prev = NULL;
    if (head != NULL) {
        head->prev = new_node;
    }
    head = new_node;
    return head;
}

struct Node* insert_end(struct Node* head) {
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    printf("Enter data for the last position: ");
    scanf("%d", &new_node->data);
    new_node->next = NULL;

    if (head == NULL) {
        new_node->prev = NULL;
        head = new_node;
    } else {
        struct Node* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = new_node;
        new_node->prev = temp;
    }
    return head;
}

struct Node* insert_position(struct Node* head) {
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    int pos;
    printf("Enter position: ");
    scanf("%d", &pos);
    printf("Enter data for a certain position: ");
    scanf("%d", &new_node->data);

    if (pos == 1) {
        new_node->next = head;
        new_node->prev = NULL;
        if (head != NULL) {
            head->prev = new_node;
        }
        head = new_node;
    } else {
        struct Node* temp = head;
        for (int i = 1; i < pos - 1 && temp != NULL; i++) {
            temp = temp->next;
        }

        if (temp == NULL) {
            printf("Invalid position\n");
        } else {
            new_node->next = temp->next;
            if (temp->next != NULL) {
                temp->next->prev = new_node;
            }
            temp->next = new_node;
            new_node->prev = temp;
        }
    }
    return head;
}

void update_by_value(struct Node* head) {
    int old_value, new_value;
    printf("Enter the old value: ");
    scanf("%d", &old_value);
    printf("Enter the new value: ");
    scanf("%d", &new_value);
    struct Node* temp = head;

    while (temp != NULL) {
        if (temp->data == old_value) {
            temp->data = new_value;
        }
        temp = temp->next;
    }
}

void update_by_position(struct Node* head) {
    int num, position;
    printf("Enter position: ");
    scanf("%d", &position);
    printf("Enter data for a certain position: ");
    scanf("%d", &num);
    struct Node* temp = head;

    for (int i = 1; i < position && temp != NULL; i++) {
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Invalid position\n");
    } else {
        temp->data = num;
    }
}

void delete_from_begin(struct Node* head) {
    if (head == NULL) {
        printf("The list is empty.\n");
        return;
    }
    struct Node* nextNode = head->next;
    if (nextNode != NULL) {
        nextNode->prev = NULL;
    }
    free(head);
    head = nextNode;
}

void delete_by_value(struct Node* head) {
    int num;
    printf("Enter value to delete: ");
    scanf("%d", &num);
    struct Node* temp = head;

    while (temp != NULL) {
        if (temp->data == num) {
            if (temp->prev != NULL) {
                temp->prev->next = temp->next;
            }
            if (temp->next != NULL) {
                temp->next->prev = temp->prev;
            }
            if (temp == head) {
                head = temp->next;
            }
            free(temp);
            return;
        }
        temp = temp->next;
    }
    printf("Value not found in the list\n");
}

void delete_by_position(struct Node* head) {
    int position;
    printf("Enter position: ");
    scanf("%d", &position);

    if (position == 1) {
        delete_from_begin(head);
    } else {
        struct Node* temp = head;
        for (int i = 1; i < position && temp != NULL; i++) {
            temp = temp->next;
        }

        if (temp == NULL) {
            printf("Invalid position\n");
        } else {
            if (temp->prev != NULL) {
                temp->prev->next = temp->next;
            }
            if (temp->next != NULL) {
                temp->next->prev = temp->prev;
            }
            free(temp);
        }
    }
}

int main() {
    printf("Operations of doubly linked list\n");
    printf("1. Insert value at first position\n");
    printf("2. Insert value at any position\n");
    printf("3. Insert value at last position\n");
    printf("4. Update Linked List by value\n");
    printf("5. Update Linked List by position\n");
    printf("6. Delete element by value\n");
    printf("7. Delete element by position\n");
    printf("8. Print Linked List\n");

    int option;
    while (1) {
        printf("Enter value for option: ");
        scanf("%d", &option);

        switch (option) {
        case 0:
            return 0;
        case 1:
            head = insert_at_begin(head);
            break;
        case 2:
            head = insert_position(head);
            break;
        case 3:
            head = insert_end(head);
            break;
        case 4:
            update_by_value(head);
            break;
        case 5:
            update_by_position(head);
            break;
        case 6:
            delete_by_value(head);
            break;
        case 7:
            delete_by_position(head);
            break;
        case 8:
            print_list(head);
            break;
        default:
            printf("Invalid option. Please try again.\n");
            break;
        }
    }
}
