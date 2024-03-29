#include <stdio.h>

int findFloor(int arr[], int size, int target) {
    int left = 0, right = size - 1;
    int floor = -1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (arr[mid] == target) {
            return arr[mid];
        } else if (arr[mid] < target) {
            floor = arr[mid];
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    return floor;
}

int findCeil(int arr[], int size, int target) {
    int left = 0, right = size - 1;
    int ceil = -1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (arr[mid] == target) {
            return arr[mid];
        } else if (arr[mid] > target) {
            ceil = arr[mid];
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }

    return ceil;
}

int findPeak(int arr[], int size) {
    int left = 0, right = size - 1;

    while (left < right) {
        int mid = left + (right - left) / 2;

        if (arr[mid] > arr[mid + 1]) {
            return arr[mid];
        } else if (arr[mid] < arr[mid + 1]) {
            left = mid + 1;
        }
    }

    return arr[left]; 
}

int findMinimum(int arr[], int size) {
    int left = 0, right = size - 1;

    while (left < right) {
        int mid = left + (right - left) / 2;

        if (arr[mid] > arr[right]) {
            left = mid + 1;
        } else {
            right = mid;
        }
    }

    return arr[left];
}

int main() {
    int arr[] = {5, 6, 7, 8
