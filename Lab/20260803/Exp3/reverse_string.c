#include <stdio.h>
#include <string.h> 

struct String {
    char str[50];
    char reversed_str[50];
    int top;
};

struct String s;

int isEmpty () {
    if (s.top == -1) {
        return 1;
    }
    else {
        return 0;
    }
}

char pop() {
    return s.str[s.top--];
}

int reverse(s.str) {
    int i = 0;
    while (!isEmpty(s.top)) {
        s.reversed_str[i++] = pop();
    }
    s.reversed_str[i] = '\0';
    return i;
}

int main() {
    printf("Enter the string to be reversed: ");
    fgets(s.str, 50, stdin);
    s.top = strlen(s.str) - 1;
    int temp_top = s.top;
    reverse(s.str);
    for (int i=0; i<=temp_top; i++) {
        printf("%c", s.reversed_str[i]);
    }
    return 0;
}