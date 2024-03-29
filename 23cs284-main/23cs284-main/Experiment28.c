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

void printList(struct Node* head) {
    while (head != NULL) {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

int getNthFromEnd(struct Node* head, int n) {
    struct Node *main_ptr = head, *ref_ptr = head;
    int count = 0;
    if (head != NULL) {
        while (count < n) {
            if (ref_ptr == NULL) {
                printf("%d is greater than the no. of nodes in the list\n", n);
                return -1;
            }
            ref_ptr = ref_ptr->next;
            count++;
        }
        while (ref_ptr != NULL) {
            main_ptr = main_ptr->next;
            ref_ptr = ref_ptr->next;
        }
        return main_ptr->data;
    }
    return -1;
}

int main() {
    struct Node* head = NULL;

    insertAtEnd(&head, 1);
    insertAtEnd(&head, 2);
    insertAtEnd(&head, 3);
    insertAtEnd(&head, 4);
    insertAtEnd(&head, 5);

    printf("Linked list: ");
    printList(head);

    int n = 2;
    int nth_from_end = getNthFromEnd(head, n);
    if (nth_from_end != -1) {
        printf("Nth node from the end of the linked list (where n = %d) is: %d\n", n, nth_from_end);
    }

    return 0;
}
