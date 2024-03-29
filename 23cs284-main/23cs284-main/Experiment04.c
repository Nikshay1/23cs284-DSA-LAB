//insertion and deletion at the beginning .

#include <stdio.h>

#define MAX_SIZE 100

int main() {
    int arr[MAX_SIZE];
    int size, i, choice;

    printf("Enter the size of the array (max %d): ", MAX_SIZE);
    scanf("%d", &size);

    printf("Enter %d elements:\n", size);
    for (i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Enter 1 for insertion, 2 for deletion at beginning: ");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            if (size >= MAX_SIZE) {
                printf("Array is full, cannot perform insertion.\n");
            } else {
                int element;
                printf("Enter the element to insert: ");
                scanf("%d", &element);

                for (i = size - 1; i >= 0; i--) {
                    arr[i + 1] = arr[i];
                }
                arr[0] = element;
                size++; 

                printf("Element inserted at the beginning successfully.\n");
            }
            break;
        case 2:
            if (size == 0) {
                printf("Array is empty, cannot perform deletion.\n");
            } else {
                for (i = 0; i < size - 1; i++) {
                    arr[i] = arr[i + 1];
                }
                size--;

                printf("Element deleted from the beginning successfully.\n");
            }
            break;
        default:
            printf("Invalid choice.\n");
            break;
    }

    printf("Array after operation:\n");
    for (i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}
