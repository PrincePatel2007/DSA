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
            len--;
            break;
        }
    }
    return 0;
}

int min_2 (int arr[], int len) {
    _remove(min(arr, len), arr, len);
    return min(arr, len-1);
}

int max_2 (int arr[], int len) {
    _remove(max(arr, len), arr, len);
    return max(arr, len-1);
}

int main() {
    int arr[5] = {2, 8, 5, 0, 4};
    int len = sizeof(arr)/sizeof(arr[0]);
    printf("Largest element is %d\n", max(arr, len));
    printf("Smallest element is %d\n", min(arr, len));
    printf("Second Largest element is %d\n", max_2(arr, len));
    printf("Second Smallest element is %d\n", min_2(arr, len));
    return 0;
}




