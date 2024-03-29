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

int maxDiameter = 0;

int maxHeight(int a, int b) {
    return (a > b) ? a : b;
}

int height(struct Node* root) {
    if (root == NULL) return -1;
    int leftHeight = height(root->left);
    int rightHeight = height(root->right);
    return 1 + maxHeight(leftHeight, rightHeight);
}

int diameter(struct Node* root) {
    if (root == NULL) return 0;
    int leftHeight = height(root->left);
    int rightHeight = height(root->right);

    int leftDiameter = diameter(root->left);
    int rightDiameter = diameter(root->right);

    maxDiameter = maxHeight(maxDiameter, leftHeight + rightHeight + 1);

    return 1 + maxHeight(leftHeight, rightHeight);
}

int main() {
    struct Node* root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->left->left = createNode(4);
    root->left->right = createNode(5);

    diameter(root);
    printf("Diameter of the binary tree: %d\n", maxDiameter);

    return 0;
}
