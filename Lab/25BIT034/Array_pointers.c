#include <stdio.h>
int main() {
    int arr[5] = {1, 2, 3, 4, 5};
    int *ptr = arr;
    printf("Pointer to Array\n%d\n", *ptr + 1);
    int a[5] = {6, 7, 8, 9, 10};
    int *arr1[5];
    for(int i = 0; i < 5; i++) {
        arr1[i] = &a[i];
    }

    printf("Array of Pointer\n");
    for(int i = 0; i < 5; i++) {
        printf("%d ", *arr1[i]);
    }

    return 0;
}