//insertion and deletion in array at user defined location

#include <stdio.h>

#define MAX_SIZE 100

int main() {
    int arr[MAX_SIZE];
    int size, i, pos, choice;

    printf("Enter the size of the array (max %d): ", MAX_SIZE);
    scanf("%d", &size);

    printf("Enter %d elements:\n", size);
    for (i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Enter 1 for insertion, 2 for deletion: ");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            printf("Enter the position for insertion (0 to %d): ", size);
            scanf("%d", &pos);
            if (pos < 0 || pos > size) {
                printf("Invalid position.\n");
            } else {
                printf("Enter the element to insert: ");
                int element;
                scanf("%d", &element);
              
                for (i = size; i > pos; i--) {
                    arr[i] = arr[i - 1];
                }
                arr[pos] = element;
                size++; 

                printf("Element inserted successfully.\n");
            }
            break;
        case 2:
            printf("Enter the position for deletion (0 to %d): ", size - 1);
            scanf("%d", &pos);
            if (pos < 0 || pos >= size) {
                printf("Invalid position.\n");
            } else {
                for (i = pos; i < size - 1; i++) {
                    arr[i] = arr[i + 1];
                }
                size--; 

                printf("Element deleted successfully.\n");
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

