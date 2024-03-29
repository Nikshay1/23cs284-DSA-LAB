#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

void insertAtPosition(struct Node** head_ref, int new_data, int position) {
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    if (new_node == NULL) {
        printf("Memory allocation failed. Unable to insert.\n");
        return;
    }
    new_node->data = new_data;
    if (position <= 0) {
        new_node->next = *head_ref;
        *head_ref = new_node;
        return;
    }
    struct Node* current = *head_ref;
    struct Node* prev = NULL;
    int i;
    for (i = 0; current != NULL && i < position; i++) {
        prev = current;
        current = current->next;
    }
    if (current == NULL) {
        printf("Position is greater than the size of the linked list. Inserting at the end.\n");
        current = *head_ref;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = new_node;
        new_node->next = NULL;
    } else {
        new_node->next = current;
        if (prev != NULL) {
            prev->next = new_node;
        } else {
            *head_ref = new_node;
        }
    }
}

void deleteAtPosition(struct Node** head_ref, int position) {
    if (*head_ref == NULL) {
        printf("Linked list is empty. Nothing to delete.\n");
        return;
    }
    if (position <= 0) {
        struct Node* temp = *head_ref;
        *head_ref = (*head_ref)->next;
        free(temp);
        return;
    }
    struct Node* current = *head_ref;
    struct Node* prev = NULL;
    int i;
    for (i = 0; current != NULL && i < position; i++) {
        prev = current;
        current = current->next;
    }
    if (current == NULL) {
        printf("Position is greater than the size of the linked list. Nothing to delete.\n");
    } else {
        if (prev != NULL) {
            prev->next = current->next;
        } else {
            *head_ref = current->next;
        }
        free(current);
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
    insertAtPosition(&head, 5, 0);
    insertAtPosition(&head, 10, 2);
    insertAtPosition(&head, 15, 1);
    insertAtPosition(&head, 20, -1);
    insertAtPosition(&head, 25, 6);
    printf("Linked list after insertions: ");
    printList(head);
    deleteAtPosition(&head, 0);
    deleteAtPosition(&head, 2);
    deleteAtPosition(&head, 10);
    deleteAtPosition(&head, -1);
    printf("Linked list after deletions: ");
    printList(head);
    return 0;
}
