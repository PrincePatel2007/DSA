#include <stdio.h>
#include <ctype.h>
#include <math.h>

#define MAX 100

struct Stack {
    int data[MAX];
    int top;
};

void push(struct Stack *s, int val) {
    s->data[++(s->top)] = val;
}

int pop(struct Stack *s) {
    return s->data[(s->top)--];
}

int evaluatePostfix(char *exp) {
    struct Stack s;
    s.top = -1;

    for (int i = 0; exp[i] != '\0'; i++) {
        // Skip whitespace
        if (isspace(exp[i])) {
            continue;
        }

        // If character is a digit, push its integer value
        if (isdigit(exp[i])) {
            push(&s, exp[i] - '0');
        } 
        // Operator handling using if-else instead of switch
        else {
            int val2 = pop(&s);
            int val1 = pop(&s);

            if (exp[i] == '+') {
                push(&s, val1 + val2);
            } else if (exp[i] == '-') {
                push(&s, val1 - val2);
            } else if (exp[i] == '*') {
                push(&s, val1 * val2);
            } else if (exp[i] == '/') {
                push(&s, val1 / val2);
            } else if (exp[i] == '^') {
                push(&s, (int)pow(val1, val2));
            }
        }
    }

    return pop(&s);
}

int main() {
    char exp[MAX];

    printf("Enter postfix expression: ");
    scanf("%s", exp);

    int result = evaluatePostfix(exp);
    printf("Result: %d\n", result);

    return 0;
}
