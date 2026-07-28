#include<stdio.h>

int main() {
    int arr_A[3][3], arr_B[3][3], arr_total[3][3];

    printf("Enter the elements of arr_A: ");
    for (int i=0; i<3; i++) {
        printf("\n");
        for (int j=0; j<3; j++) {
            scanf("%d", &arr_A[i][j]);
        }
    }

    printf("\nEnter the elements of arr_B: ");
    for (int i=0; i<3; i++) {
        printf("\n");
        for (int j=0; j<3; j++) {
            scanf("%d", &arr_B[i][j]);
        }
    }

    for (int i=0; i<3; i++) {
        for (int j=0; j<3; j++) {
            arr_total[i][j] = arr_A[i][j] + arr_B[i][j];
        }
    }

    for (int i=0; i<3; i++) {
        printf("\n");
        for (int j=0; j<3; j++) {
            printf("%d ", arr_total[i][j]);
        }
    }

    return 0;
}