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

struct Node* mergeSortedLists(struct Node* head1, struct Node* head2) {
    struct Node* merged = NULL;
    struct Node* tail = NULL;
    while (head1 != NULL && head2 != NULL) {
        if (head1->data <= head2->data) {
            if (merged == NULL) {
                merged = tail = head1;
            } else {
                tail->next = head1;
                tail = tail->next;
            }
            head1 = head1->next;
        } else {
            if (merged == NULL) {
                merged = tail = head2;
            } else {
                tail->next = head2;
                tail = tail->next;
            }
            head2 = head2->next;
        }
    }
    if (head1 == NULL) {
        if (merged == NULL) {
            merged = head2;
        } else {
            tail->next = head2;
        }
    } else {
        if (merged == NULL) {
            merged = head1;
        } else {
            tail->next = head1;
        }
    }
    return merged;
}

int main() {
    struct Node* head1 = NULL;
    struct Node* head2 = NULL;

    insertAtEnd(&head1, 1);
    insertAtEnd(&head1, 3);
    insertAtEnd(&head1, 5);

    insertAtEnd(&head2, 2);
    insertAtEnd(&head2, 4);
    insertAtEnd(&head2, 6);

    printf("First sorted linked list: ");
    printList(head1);
    printf("Second sorted linked list: ");
    printList(head2);

    struct Node* mergedList = mergeSortedLists(head1, head2);

    printf("Merged sorted linked list: ");
    printList(mergedList);

    return 0;
}
