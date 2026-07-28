#include<stdio.h>

int neutralize(char ch) {
    if (ch>='a' && ch<='z') {
        ch -= 32;
    }
    return ch;
}

int actual_len(char *arr) {
    int count=0;
    while (arr[count]!='\0') {
        count++;
    }
    return count;
}

int main() {
    char arr[50] = "Worrongongegnognorrow";
    char new_arr[50];
    int is_palindrome = 1;
    for (int i=0; i<actual_len(arr); i++) {
        new_arr[i] = neutralize(arr[i]);
        printf("%d ",new_arr[i]); // Debugging
    }
    for (int i=0; i<actual_len(arr); i++) {
        printf("%d", neutralize(arr[i])); // debugging
        printf("=%d ", new_arr[actual_len(arr)-i]); // debugging
        if (neutralize(arr[i])!=new_arr[actual_len(arr)-i]) {
            is_palindrome = 0;
            //break; debugging
        }
    }
    printf("Palindrome status: %d", is_palindrome);
    return 0;
}