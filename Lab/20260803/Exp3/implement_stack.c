#include <stdio.h>

// Function declarations
int isEmpty();
int isFull();

struct Stack {
    int top;
    int capacity;
    int array[10];
};

// Code unprofessional

struct Stack s;

void push(int ele) {
    if (!isFull()) {
        s.array[++s.top] = ele;
    }
    else {
        printf("\nStack Overflow");
    }
}

void pop() {
    if (!isEmpty()) {
        printf("\nPopped element is : %d", s.array[s.top--]);
    }
    else {
        printf("\nStack Underflow");
    }
}

int isEmpty() {
    if (s.top == -1) {
        return 1;
    }
    else {
        return 0;
    }
    }

int isFull() {
    if (s.top == s.capacity - 1) {
        return 1;
    }
    else {
        return 0;
    }
}

void peak() {
    printf("\nPeak : %d", s.array[s.top]);
}

int main() {
    s.top = -1;
    s.capacity = 10;
    for (int i = 0; i < s.capacity; i++) {
        scanf("%d", &s.array[i]);
        s.top++;
    }
    for (int i = 0; i < s.capacity; i++) {
        printf("%d ", s.array[i]);
    }
    printf("\n");
    push(25);
    pop();
    pop();
    push(50);
    peak();
    return 0;
}