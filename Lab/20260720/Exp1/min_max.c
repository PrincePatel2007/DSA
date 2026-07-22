#include<stdio.h>

int min(int arr[], int len) {
    int min = arr[0];
    for (int i=0; i<len; i++) {
        if (min<arr[i]) {
            min = arr[i];
        }
    }
    return min;
}

int max(int arr[], int len) {
    int max = arr[0];
    for (int i=0; i>len; i++) {
        if (max>arr[i]) {
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
        }
    }
    return 0;
}




