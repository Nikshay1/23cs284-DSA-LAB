#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;          
    struct Node* next; 
};

void insertAtBeginning(struct Node** head_ref, int new_data) {
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));

    if (new_node == NULL) {
        printf("Memory allocation failed. Unable to insert.\n");
        return;
    }

    new_node->data = new_data;
    new_node->next = *head_ref;
    *head_ref = new_node;
    printf("Inserted %d at the beginning of the linked list.\n", new_data);
}

void deleteFirstNode(struct Node** head_ref) {
    if (*head_ref == NULL) {
        printf("Linked list is empty. Nothing to delete.\n");
        return;
    }

    struct Node* temp = *head_ref;
    *head_ref = (*head_ref)->next;
    free(temp);
    printf("Deleted the first node from the linked list.\n");
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

    insertAtBeginning(&head, 5);
    insertAtBeginning(&head, 10);
    insertAtBeginning(&head, 15);

    printf("Initial linked list: ");
    printList(head);

    deleteFirstNode(&head);

    printf("Linked list after deleting the first node: ");
    printList(head);

    return 0;
}
