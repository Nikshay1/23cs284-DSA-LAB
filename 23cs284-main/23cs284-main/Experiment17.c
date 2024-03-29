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
    
    printf("Inserted %d at the end of the linked list.\n", new_data);
}

void deleteLastNode(struct Node** head_ref) {
    if (*head_ref == NULL) {
        printf("Linked list is empty. Nothing to delete.\n");
        return;
    }
    
    if ((*head_ref)->next == NULL) {
        free(*head_ref);
        *head_ref = NULL;
        printf("Deleted the last node from the linked list.\n");
        return;
    }
    
    struct Node* second_last = *head_ref;
    while (second_last->next->next != NULL) {
        second_last = second_last->next;
    }
    
    free(second_last->next);
    second_last->next = NULL;
    
    printf("Deleted the last node from the linked list.\n");
}

void printList(struct Node* node) {
    while (node != NULL) {
        printf("%d ->", node->data);
        node = node->next;
    }
    printf("NULL\n");
}

int main() {
    struct Node* head = NULL;

    insertAtEnd(&head, 5);
    insertAtEnd(&head, 10);
    insertAtEnd(&head, 15);

    printf("Initial linked list: ");
    printList(head);

    deleteLastNode(&head);

    printf("Linked list after deleting the last node: ");
    printList(head);

    return 0;
}
