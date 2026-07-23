#include<stdio.h>

int min(int arr[], int len) {
    int min = arr[0];
    for (int i=0; i<len; i++) {
        if (min>arr[i]) {
            min = arr[i];
        }
    }
    return min;
}

int max(int arr[], int len) {
    int max = arr[0];
    for (int i=0; i<len; i++) {
        if (max<arr[i]) {
            max = arr[i];
        }
    }
    return max;
}

int _remove(int el, int arr[], int len) {
    for (int i=0; i<len; i++) {
        if (arr[i]==el) {
            for (int j=i; j<len-1; j++) {
                arr[j] = arr[j+1];
            }
            arr[len-1] = 0;
            break;
        }
    }
    return 0;
}

int min_2 (int arr[], int len) {
    _remove(min(arr, len), arr, len);
    return min(arr, len-1);
}

int main() {
    int arr[5] = {2, 8, 5, 9, 4};
    int len = 5;
    printf("%d", min_2(arr, 5));
    for (int i=0; i<len-1; i++) {
        printf("%d   ", arr[i]);
    }
    return 0;
}




