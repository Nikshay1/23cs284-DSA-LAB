#include <stdio.h>

int linearSearch(int arr[], int size, int key) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == key) {
            return i; 
        }
    }
    return -1;
}

int main() {
    int arr[] = {12, 45, 78, 34, 56};
    int size = sizeof(arr) / sizeof(arr[0]);
    int key, index;

    printf("Enter the element to search: ");
    scanf("%d", &key);

    index = linearSearch(arr, size, key);

    if (index != -1) {
        printf("Element found at index %d.\n", index);
    } else {
        printf("Element not found in the array.\n");
    }

    return 0;
}
