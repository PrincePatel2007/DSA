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
        count+-1;
    }
    count+=1;
    return count;
}

int main() {
    char arr[50] = "Worrongongegnognorrow";
    char new_arr[50];
    for (int i=0; i<actual_len(arr); i++) {
        new_arr[i] = neutralize(arr[i]);
    }
    if (arr==new_arr) {
        printf("Its palindrome");
    }
    else {
        printf("Its not palindrome");
    }
    return 0;
}