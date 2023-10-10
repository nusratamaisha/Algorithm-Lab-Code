
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
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
    printf("Enter data for first position: ");
    scanf("%d", &new_node->data);
    new_node->next = head;
    head = new_node;
    return head;
}

struct Node* insert_end(struct Node* head) {
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    printf("Enter data for last position: ");
    scanf("%d", &new_node->data);
    new_node->next = NULL;

    if (head == NULL) {
        head = new_node;
    }
    else {
        struct Node* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = new_node;
    }
    return head;
}

struct Node* insert_position(struct Node* head) {
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    int pos;
    printf("Enter position: ");
    scanf("%d", &pos);
    printf("Enter data for certain position: ");
    scanf("%d", &new_node->data);

    if (pos == 1) {
        new_node->next = head;
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
            temp->next = new_node;
        }
    }
    return head;
}

void update_by_value(struct Node* head) {
    struct Node* temp = head;
    int old_value, new_value;
    printf("Enter the old value: ");
    scanf("%d", &old_value);
    printf("Enter the new value: ");
    scanf("%d", &new_value);
    if (temp == NULL) {
        printf("The linked list is not initialized.\n");
    } else {
        while (temp != NULL) {
            if (temp->data == old_value) {
                temp->data = new_value;
            }
            temp = temp->next;
        }
    }
}

void update_by_position(struct Node* head) {
    int num, position;
    printf("Enter position: ");
    scanf("%d", &position);
    printf("Enter data for certain position: ");
    scanf("%d", &num);
    if (position == 1) {
        head->data = num;
    } else {
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
}

void delete_from_begin(struct Node* head) {
    if (head == NULL) {
        printf("The list is empty.\n");
        return;
    }
    struct Node* nextNode = head->next;
    head->data = nextNode->data;
    head->next = nextNode->next;
    free(nextNode);
}

void delete_by_value(struct Node* head) {
    int num;
    printf("Enter value to delete: ");
    scanf("%d", &num);
    struct Node* temp = head;
    if (head->data == num) {
        delete_from_begin(head);
    } else if (temp == NULL) {
        printf("Invalid position\n");
    }
    while (temp != NULL) {
        if (temp->next != NULL && temp->next->data == num) {
            struct Node* nextNode = temp->next;
            temp->next = nextNode->next;
            free(nextNode);
        }
        temp = temp->next;
    }
}

void delete_by_position(struct Node* head) {
    int position;
    printf("Enter position: ");
    scanf("%d", &position);
    if (position == 1) {
        delete_from_begin(head);
    } else {
        struct Node* temp = head;

        for (int i = 1; i < position - 1 && temp != NULL; i++) {
            temp = temp->next;
        }

        if (temp == NULL) {
            printf("Invalid position\n");
        } else {
            struct Node* nextNode = temp->next;
            temp->next = nextNode->next;
            free(nextNode);
        }
    }
}

int main() {
    printf("Operations of singly linked list\n");
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
