#include<stdio.h>

int len (int arr[]) {
    int _length = sizeof(arr) / sizeof(arr[0]);
    return _length;
}

int min(int arr[]) {
    int min = arr[0];
    for (int i=0; i<len(arr); i++) {
        if (min<arr[i]) {
            min = arr[i];
        }
    }
    return min;
}

int max(int arr[]) {
    int max = arr[0];
    for (int i=0; i<len(arr); i++) {
        if (max>arr[i]) {
            max = arr[i];
        }
    }
    return max;
}

int remove(int el, int arr[]) {
    for (int i=0; i<len(arr); i++) {
        if (arr[i]==el) {
            for (int j=i; j<len-1; j++) {
                arr[j] = arr[j+1];
            }
        }
    }
    return NULL;
}

int main() {
    int arr[5] = {2,6,4,9,7};
    remove(9, arr);
    for (int i=0; i<len(arr); i++) {
        printf("%d", arr[i]);
    }
}




