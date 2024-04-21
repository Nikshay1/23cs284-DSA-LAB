#include <stdio.h>
#include <stdlib.h>
#include <map>

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

void bottomView(struct Node* root) {
    if (root == NULL) return;

    int hd = 0;
    std::map<int, int> bottomMap;
    std::map<struct Node*, int> levelMap;

    struct Node* queue[1000];
    int front = -1, rear = -1;
    queue[++rear] = root;
    levelMap[root] = hd;

    while (front != rear) {
        struct Node* curr = queue[++front];
        hd = levelMap[curr];

        bottomMap[hd] = curr->data;

        if (curr->left) {
            queue[++rear] = curr->left;
            levelMap[curr->left] = hd - 1;
        }
        if (curr->right) {
            queue[++rear] = curr->right;
            levelMap[curr->right] = hd + 1;
        }
    }

    for (auto it : bottomMap) {
        printf("%d ", it.second);
    }
    printf("\n");
}

int main() {
    struct Node* root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->left->right = createNode(4);
    root->right->left = createNode(5);
    root->right->right = createNode(6);
    root->right->left->left = createNode(7);
    root->right->left->right = createNode(8);

    printf("Bottom view of the binary tree: ");
    bottomView(root);

    return 0;
}
