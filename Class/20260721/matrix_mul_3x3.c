#include<stdio.h>
int main() {
    int arr1[3][3], arr2[3][3], _mul[3][3];

    printf("Enter the elements of first 3x3 matrix:\n");
    for (int i=0; i<3; i++) {
        printf("\n");
        for (int j=0; j<3; j++) {
            scanf("%d", &arr1[i][j]);
        }
    }

    printf("\nEnter the elements of second 3x3 matrix:\n");
    for (int i=0; i<3; i++) {
        printf("\n");
        for (int j=0; j<3; j++) {
            scanf("%d", &arr2[i][j]);
        }
    }
    
    printf("The product of the two matrices is:\n");
    for (int i=0; i<3; i++) {
        for (int j=0; j<3; j++) {
            _mul[i][j] = arr1[i][0]*arr2[0][j] + arr1[i][1]*arr2[1][j] + arr1[i][2]*arr2[2][j];
        }
    }

    for (int i=0; i<3; i++) {
        printf("\n");
        for (int j=0; j<3; j++) {
            printf("%d ", _mul[i][j]);
        }
    }
    return 0;
}