#include<stdio.h>

#define MAX 5

struct Stack {
    int data[MAX];
    int top;
};

int is_Full(struct Stack *s) {
    if (s->top == MAX -1) {
        return 1;
    }
    else {
        return 0;
    }
}

int is_Empty(struct Stack *s) {
    if (s->top == -1) {
        return 1;
    }
    else {
        return 0;
    }
}

void push(struct Stack *s, int ele) {
    if (!is_Full(s)) {
        s->data[++s->top] = ele;
        printf("\nPushed element: %d", ele);
    }
    else {
        printf("\nStack Overflow");
    }
}

void pop(struct Stack *s) {
    if (!is_Empty(s)) {
        printf("\nPopped Element: %d", s->data[s->top--]);
    }
    else {
        printf("\nStack Underflow");
    }
}

void peek(struct Stack *s) {
    if (!is_Empty(s)) {
        printf("\nPeek: %d", s->data[s->top]);
    }
    else {
        printf("\nStack is empty");
    }
}

int main() {
    struct Stack s;
    s.top = -1;
    pop(&s);
    push(&s, 7);
    push(&s, 5);
    push(&s, 4);
    push(&s, 6);
    push(&s, 1);
    push(&s, 3);
    pop(&s);
    pop(&s);
    pop(&s);
    peek(&s);
    return 0;
}