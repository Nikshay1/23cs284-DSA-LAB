#include <stdio.h>

#define NUM_STUDENTS 3
#define NUM_SUBJECTS 5

int main() {
    int marks[NUM_STUDENTS][NUM_SUBJECTS];
    int total[NUM_STUDENTS] = {0};
    float average[NUM_SUBJECTS] = {0};

    for (int i = 0; i < NUM_STUDENTS; i++) {
        printf("Enter marks for Student %d:\n", i + 1);
        for (int j = 0; j < NUM_SUBJECTS; j++) {
            printf("Enter marks for Subject %d: ", j + 1);
            scanf("%d", &marks[i][j]);
            total[i] += marks[i][j];
            average[j] += marks[i][j];
        }
    }

    for (int j = 0; j < NUM_SUBJECTS; j++) {
        average[j] /= NUM_STUDENTS;
    }

    printf("\nTotal marks for each student:\n");
    for (int i = 0; i < NUM_STUDENTS; i++) {
        printf("Student %d: %d\n", i + 1, total[i]);
    }

    printf("\nAverage marks for each subject:\n");
    for (int j = 0; j < NUM_SUBJECTS; j++) {
        printf("Subject %d: %.2f\n", j + 1, average[j]);
    }

    return 0;
}
