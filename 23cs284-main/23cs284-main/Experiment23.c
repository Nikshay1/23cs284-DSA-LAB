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
    if (*head_ref == NULL) {
        new_node->next = new_node;
        *head_ref = new_node;
        return;
    }
    struct Node* last = *head_ref;
    while (last->next != *head_ref) {
        last = last->next;
    }
    last->next = new_node;
    new_node->next = *head_ref;
}

void printList(struct Node* head) {
    struct Node* current = head;
    if (head != NULL) {
        do {
            printf("%d -> ", current->data);
            current = current->next;
        } while (current != head);
        printf("\n");
    } else {
        printf("List is empty.\n");
    }
}

int main() {
    struct Node* head = NULL;
    insertAtEnd(&head, 1);
    insertAtEnd(&head, 2);
    insertAtEnd(&head, 3);
    insertAtEnd(&head, 4);
    printf("Circular linked list: ");
    printList(head);
    return 0;
}
