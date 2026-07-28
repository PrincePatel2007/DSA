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
    }
    for (int i=0; i<actual_len(arr); i++) {
        if (neutralize(arr[i])!=new_arr[actual_len(arr)-i-1]) {
            is_palindrome = 0;
            break;
        }
    }

    if (is_palindrome==1) {
        printf("String is palindrome");
    }
    else {
        printf("String is not palindrome");
    }

    return 0;
}