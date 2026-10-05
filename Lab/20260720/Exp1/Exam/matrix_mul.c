#include<stdio.h>

int main() {
    int arr_A[3][3], arr_B[3][3], arr_Total[3][3];

    for (int i=0; i<3; i++) {
        for (int j=0; j<3; j++) {
            scanf("%d", &arr_A[i][j]);
        }
        printf("\n");
    }

    for (int i=0; i<3; i++) {
        for (int j=0; j<3; j++) {
            scanf("%d", &arr_B[i][j]);
        }
        printf("\n");
    }

    for (int i=0; i<3; i++) {
        for (int j=0; j<3; j++) {
            printf("%d ", arr_Total[i][j] = arr_A[i][0]*arr_B[0][j] + arr_A[i][1]*arr_B[1][j] + arr_A[i][2]*arr_B[2][j]);
        }
        printf("\n");
    }
    return 0;
}