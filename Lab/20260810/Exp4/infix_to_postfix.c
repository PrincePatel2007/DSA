#include <stdio.h>
#include <ctype.h>

#define MAX 20
struct stack {
    char arr[MAX];
    int top;
};

void push(char ele, struct stack *s) {
    if (s->top == MAX - 1) {
        printf("Stack Overflow!\n");
    } else {
        s->arr[++(s->top)] = ele;
    }
}

char pop(struct stack *s) {
    if (s->top == -1) {
        return '\0';
    }
    return s->arr[(s->top)--];
}

int priority(char ele) {
    if (ele == '+' || ele == '-')
        return 1;
    if (ele == '*' || ele == '/')
        return 2;
    if (ele == '$' || ele == '^')
        return 3;
    if (ele == '(')
        return 0;
    return -1;
}

int main() {
    struct stack s;
    s.top = -1;

    char exp[MAX];
    printf("Enter Expression : ");
    scanf("%s", exp);

    printf("Postfix Expression: ");

    for (int i = 0; exp[i] != '\0'; i++) {
        char ch = exp[i];
        if (isalnum(ch)) {
            printf("%c", ch);
        }
        else if (ch == '(') {
            push(ch, &s);
        }
        else if (ch == ')') {
            while (s.top != -1 && s.arr[s.top] != '(') {
                printf("%c", pop(&s));
            }
            if (s.top != -1) {
                pop(&s);
            }
        }
        else {
            while (s.top != -1 && priority(s.arr[s.top]) >= priority(ch) && ch != '$') {
                printf("%c", pop(&s));
            }
            push(ch, &s);
        }
    }

    while (s.top != -1) {
        printf("%c", pop(&s));
    }
    printf("\n");

    return 0;
}
