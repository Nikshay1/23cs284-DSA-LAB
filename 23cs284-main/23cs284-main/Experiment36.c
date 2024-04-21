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

struct QueueNode {
    struct Node* node;
    int hd;
};

struct Queue {
    struct QueueNode** items;
    int front;
    int rear;
};

struct Queue* createQueue(int size) {
    struct Queue* queue = (struct Queue*)malloc(sizeof(struct Queue));
    queue->items = (struct QueueNode**)malloc(size * sizeof(struct QueueNode*));
    queue->front = -1;
    queue->rear = -1;
    return queue;
}

int isEmpty(struct Queue* queue) {
    return (queue->front == -1);
}

void enqueue(struct Queue* queue, struct Node* node, int hd) {
    struct QueueNode* queueNode = (struct QueueNode*)malloc(sizeof(struct QueueNode));
    queueNode->node = node;
    queueNode->hd = hd;
    
    if (queue->front == -1) {
        queue->front = 0;
    }
    queue->rear++;
    queue->items[queue->rear] = queueNode;
}

struct QueueNode* dequeue(struct Queue* queue) {
    if (isEmpty(queue)) {
        return NULL;
    }
    struct QueueNode* item = queue->items[queue->front];
    queue->front++;
    if (queue->front > queue->rear) {
        queue->front = -1;
        queue->rear = -1;
    }
    return item;
}

void topView(struct Node* root) {
    if (root == NULL) return;

    struct Queue* queue = createQueue(100);
    enqueue(queue, root, 0);

    while (!isEmpty(queue)) {
        struct QueueNode* node = dequeue(queue);
        int hd = node->hd;

        printf("%d ", node->node->data);

        if (node->node->left != NULL) {
            enqueue(queue, node->node->left, hd - 1);
        }
        if (node->node->right != NULL) {
            enqueue(queue, node->node->right, hd + 1);
        }

        free(node);
    }

    free(queue->items);
    free(queue);
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

    printf("Top view of the binary tree: ");
    topView(root);
    printf("\n");

    return 0;
}
