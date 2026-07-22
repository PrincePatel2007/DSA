#include<stdio.h>

int min(int arr[]) {
    int len = sizeof(arr) / sizeof(arr[0]);
    int min = arr[0];
    for (int i=0; i<len; i++) {
        if (min<arr[i]) {
            min = arr[i];
        }
    }
    return 0;
}

int max(int arr[]) {
    int len = sizeof(arr) / sizeof(arr[0]);
    int max = arr[0];
    for (int i=0; i<len; i++) {
        if (max>arr[i]) {
            max = arr[i];
        }
    }
    return 0;
}

int remove(int el, int arr[]) {
    int len = sizeof(arr) / sizeof(arr[0]);
    for (int i=0; i<len; i++) {
        if (arr[i]==el) {
            for (int j=i; j<len-1; j++) {
                arr[j] = arr[j+1];
            }
        }
    }
    return 0;
}




