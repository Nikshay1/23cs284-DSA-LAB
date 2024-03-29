#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

void preorderFromPostorder(int post[], int n) {
    if (n <= 0) return;

    int rootValue = post[n - 1];
    printf("%d ", rootValue);

    int rightCount = 0;
    while (post[rightCount] >= rootValue && rightCount < n - 1) {
        rightCount++;
    }

    preorderFromPostorder(post, rightCount);
    preorderFromPostorder(post + rightCount, n - rightCount - 1);
}

int main() {
    int postorder[] = {4, 5, 2, 6, 7, 3, 1};
    int n = sizeof(postorder) / sizeof(postorder[0]);

    printf("Preorder traversal from postorder traversal: ");
    preorderFromPostorder(postorder, n);
    printf("\n");

    return 0;
}
