#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

void insertAtEnd(struct Node** head_ref, int new_data) {
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    if (new_node == NULL) {
        printf("Memory allocation failed. Unable to insert.\n");
        return;
    }
    new_node->data = new_data;
    new_node->next = NULL;
    if (*head_ref == NULL) {
        *head_ref = new_node;
        return;
    }
    struct Node* last = *head_ref;
    while (last->next != NULL) {
        last = last->next;
    }
    last->next = new_node;
}

void searchAndPrint(struct Node* head, int value) {
    struct Node* current = head;
    int found = 0;
    while (current != NULL) {
        if (current->data == value) {
            printf("Value %d found in the linked list.\n", value);
            found = 1;
            break;
        }
        current = current->next;
    }
    if (!found) {
        printf("Value %d not found in the linked list.\n", value);
    }
}

void printList(struct Node* node) {
    while (node != NULL) {
        printf("%d -> ", node->data);
        node = node->next;
    }
    printf("NULL\n");
}

int main() {
    struct Node* head = NULL;
    insertAtEnd(&head, 5);
    insertAtEnd(&head, 10);
    insertAtEnd(&head, 15);
    insertAtEnd(&head, 20);
    printf("Linked list: ");
    printList(head);
    searchAndPrint(head, 10);
    searchAndPrint(head, 25);
    return 0;
}
