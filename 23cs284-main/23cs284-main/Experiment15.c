#include <stdio.h>

#define MAX_SIZE 100

struct SparseMatrixElement {
    int row;
    int col;
    int value;
};

struct SparseMatrix {
    int rows;
    int cols;
    int count;
    struct SparseMatrixElement data[MAX_SIZE];
};

void addSparseMatrices(struct SparseMatrix A, struct SparseMatrix B) {
    if (A.rows != B.rows || A.cols != B.cols) {
        printf("Error: Matrices must have the same dimensions for addition.\n");
        return;
    }

    struct SparseMatrix result;
    result.rows = A.rows;
    result.cols = A.cols;
    result.count = 0;

    int i = 0, j = 0;

    while (i < A.count && j < B.count) {
        if (A.data[i].row < B.data[j].row || (A.data[i].row == B.data[j].row && A.data[i].col < B.data[j].col)) {
            result.data[result.count++] = A.data[i++];
        } else if (A.data[i].row > B.data[j].row || (A.data[i].row == B.data[j].row && A.data[i].col > B.data[j].col)) {
            result.data[result.count++] = B.data[j++];
        } else {
            result.data[result.count].row = A.data[i].row;
            result.data[result.count].col = A.data[i].col;
            result.data[result.count].value = A.data[i].value + B.data[j].value;
            result.count++;
            i++;
            j++;
        }
    }

    while (i < A.count) {
        result.data[result.count++] = A.data[i++];
    }

    while (j < B.count) {
        result.data[result.count++] = B.data[j++];
    }

    printf("Result of addition:\n");
    for (int k = 0; k < result.count; k++) {
        printf("(%d, %d, %d)\n", result.data[k].row, result.data[k].col, result.data[k].value);
    }
}

void multiplySparseMatrices(struct SparseMatrix A, struct SparseMatrix B) {
    if (A.cols != B.rows) {
        printf("Error: Number of columns in matrix A must be equal to number of rows in matrix B for multiplication.\n");
        return;
    }

    struct SparseMatrix result;
    result.rows = A.rows;
    result.cols = B.cols;
    result.count = 0;

    for (int i = 0; i < A.count; i++) {
        for (int j = 0; j < B.count; j++) {
            if (A.data[i].col == B.data[j].row) {
                result.data[result.count].row = A.data[i].row;
                result.data[result.count].col = B.data[j].col;
                result.data[result.count].value += A.data[i].value * B.data[j].value;
                result.count++;
            }
        }
    }

    printf("Result of multiplication:\n");
    for (int k = 0; k < result.count; k++) {
        printf("(%d, %d, %d)\n", result.data[k].row, result.data[k].col, result.data[k].value);
    }
}

int main() {
    struct SparseMatrix A = {3, 3, 4, {{0, 0, 1}, {1, 1, 2}, {2, 0, 3}, {2, 2, 4}}};
    struct SparseMatrix B = {3, 3, 3, {{0, 0, 2}, {1, 2, 3}, {2, 1, 4}}};

    printf("Matrix A:\n");
    for (int i = 0; i < A.count; i++) {
        printf("(%d, %d, %d)\n", A.data[i].row, A.data[i].col, A.data[i].value);
    }
    printf("\n");

    printf("Matrix B:\n");
    for (int i = 0; i < B.count; i++) {
        printf("(%d, %d, %d)\n", B.data[i].row, B.data[i].col, B.data[i].value);
    }
    printf("\n");

    addSparseMatrices(A, B);
    printf("\n");

    multiplySparseMatrices(A, B);

    return 0;
}
