#include <stdio.h>
#include <string.h>

struct String {
    char str[50];
    char reverse_str[50];
    int top;
};

int isEmpty(struct String *s) {
    if (s->top == -1) {
        return 1;
    }
    else {
        return 0;
    }
}

char pop(struct String *s) {
    return (s->str[s->top--]);
}

void reverse(struct String *s) {
    int i = 0;
    while(!isEmpty(s)) {
        s->reverse_str[i++] = pop(s);
    }
    s->reverse_str[i] = '\0';
}

int main() {
    struct String s1;
    printf("Enter the string to be reversed: ");
    fgets(s1.str, 50, stdin);
    s1.top = strlen(s1.str) - 1;
    reverse(&s1);
    printf("Reversed string: %s\n", s1.reverse_str);
    return 0;
}