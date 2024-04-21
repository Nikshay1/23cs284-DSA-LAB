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

void postorderFromPreorder(int pre[], int n) {
    if (n <= 0) return;

    int rootValue = pre[0];
    int leftCount = 0;
    while (pre[leftCount + 1] <= rootValue && leftCount < n - 1) {
        leftCount++;
    }

    postorderFromPreorder(pre + 1, leftCount);
    postorderFromPreorder(pre + leftCount + 1, n - leftCount - 1);
    printf("%d ", rootValue);
}

int main() {
    int preorder[] = {1, 2, 4, 5, 3, 6, 7};
    int n = sizeof(preorder) / sizeof(preorder[0]);

    printf("Postorder traversal from preorder traversal: ");
    postorderFromPreorder(preorder, n);
    printf("\n");

    return 0;
}
