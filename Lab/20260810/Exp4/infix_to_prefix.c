#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAX 50

struct stack {
    int top;
    char arr[MAX];
};

void push(char ch, struct stack *s) {
    if (s->top == MAX - 1) {
        printf("Stack Overflow!\n");
    } else {
        s->arr[++(s->top)] = ch;
    }
}

char pop(struct stack *s) {
    if (s->top == -1) {
        return '\0';
    }
    return s->arr[(s->top)--];
}

int priority(char ch) {
    if (ch == '+' || ch == '-')
        return 1;
    if (ch == '*' || ch == '/')
        return 2;
    if (ch == '^' || ch == '$')
        return 3;
    return 0;
}

int main() {
    struct stack s;
    s.top = -1;

    char exp[MAX], rev[MAX], ans[MAX];
    printf("Enter Infix Expression: ");
    scanf("%s", exp);

    int l = strlen(exp);

    for (int i=0; i<l; i++) {
        rev[i] = exp[l-1-i];
    }
    rev[l] = '\0';

    int k = 0;

    for (int i = 0; rev[i] != '\0'; i++) {
        char ch = rev[i];

        if (isalnum(ch)) {
            ans[k++] = ch;
        } 
        else if (ch == ')') {
            push(ch, &s);
        } 
        else if (ch == '(') {
            while (s.top != -1 && s.arr[s.top] != ')') {
                ans[k++] = pop(&s);
            }
            if (s.top != -1) {
                pop(&s);
            }
        } 
        else {
            while (s.top != -1 && s.arr[s.top] != ')' &&
                  ((ch != '^' && ch != '$' && priority(s.arr[s.top]) > priority(ch)) ||
                   ((ch == '^' || ch == '$') && priority(s.arr[s.top]) >= priority(ch)))) {
                ans[k++] = pop(&s);
            }
            push(ch, &s);
        }
    }

    while (s.top != -1) {
        ans[k++] = pop(&s);
    }
    ans[k] = '\0';
    printf("Prefix Expression: ");
    for (int i = k - 1; i >= 0; i--) {
        printf("%c", ans[i]);
    }
    printf("\n");

    return 0;
}
