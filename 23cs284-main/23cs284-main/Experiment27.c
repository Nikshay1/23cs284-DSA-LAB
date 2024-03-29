#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct Node {
    char data;
    struct Node* next;
};

void insertAtEnd(struct Node** head_ref, char new_data) {
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
        printf("%c -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

bool isPalindrome(struct Node* head) {
    if (head == NULL || head->next == NULL) {
        return true;
    }

    struct Node* slow = head;
    struct Node* fast = head;

    // Find the middle of the linked list
    while (fast->next != NULL && fast->next->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }

    // Reverse the second half of the linked list
    struct Node* prev = NULL;
    struct Node* current = slow->next;
    struct Node* next_node;
    while (current != NULL) {
        next_node = current->next;
        current->next = prev;
        prev = current;
        current = next_node;
    }
    slow->next = prev;

    // Compare the first half and the reversed second half of the linked list
    struct Node* p1 = head;
    struct Node* p2 = prev;
    while (p2 != NULL) {
        if (p1->data != p2->data) {
            return false;
        }
        p1 = p1->next;
        p2 = p2->next;
    }

    return true;
}

int main() {
    struct Node* head = NULL;

    insertAtEnd(&head, 'r');
    insertAtEnd(&head, 'a');
    insertAtEnd(&head, 'd');
    insertAtEnd(&head, 'a');
    insertAtEnd(&head, 'r');

    printf("Linked list: ");
    printList(head);

    if (isPalindrome(head)) {
        printf("Linked list is a palindrome.\n");
    } else {
        printf("Linked list is not a palindrome.\n");
    }

    return 0;
}
