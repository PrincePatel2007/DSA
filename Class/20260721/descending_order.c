#include<stdio.h>

int main() {
    int arr[5] = {2,1,4,5,7};
    int temp;
    for (int i=0; i<5; i++) {
        for (int j=i+1; j<5; j++) {
            if (arr[i]<arr[j]) {
                temp = arr[j];
                arr[j] = arr[i];
                arr[i] = temp;
            }
        }
    }
    for (int k=0; k<5; k++) {
        printf("%d ", arr[k]);
    }
    return 0;
}