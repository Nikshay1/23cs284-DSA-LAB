#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

int length(struct Node* head) {
    int len = 0;
    while (head != NULL) {
        len++;
        head = head->next;
    }
    return len;
}

struct Node* findMergePoint(struct Node* head1, struct Node* head2) {
    int len1 = length(head1);
    int len2 = length(head2);
    int diff = abs(len1 - len2);
    if (len1 > len2) {
        for (int i = 0; i < diff; i++) {
            head1 = head1->next;
        }
    } else {
        for (int i = 0; i < diff; i++) {
            head2 = head2->next;
        }
    }
    while (head1 != NULL && head2 != NULL) {
        if (head1 == head2) {
            return head1;
        }
        head1 = head1->next;
        head2 = head2->next;
    }
    return NULL;
}

void printList(struct Node* node) {
    while (node != NULL) {
        printf("%d -> ", node->data);
        node = node->next;
    }
    printf("NULL\n");
}

int main() {
    struct Node* head1 = (struct Node*)malloc(sizeof(struct Node));
    struct Node* head2 = (struct Node*)malloc(sizeof(struct Node));
    head1->data = 1;
    head1->next = NULL;
    head2->data = 10;
    head2->next = NULL;
    struct Node* merge_point = (struct Node*)malloc(sizeof(struct Node));
    merge_point->data = 20;
    merge_point->next = NULL;
    head1->next = merge_point;
    head2->next = merge_point;
    printf("Linked list 1: ");
    printList(head1);
    printf("Linked list 2: ");
    printList(head2);
    struct Node* result = findMergePoint(head1, head2);
    if (result != NULL) {
        printf("Merge point found at data: %d\n", result->data);
    } else {
        printf("No merge point found.\n");
    }
    free(head1);
    free(head2);
    free(merge_point);
    return 0;
}
