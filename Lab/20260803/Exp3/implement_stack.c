#include <stdio.h>

// Function declarations
int isEmpty();
int isFull();

struct Stack {
    int top;
    int capacity;
    int array[10];
};

struct Stack s;

void push(int ele) {
    if (!isFull()) {
        s.array[++s.top] = ele;
    }
    else {
        printf("Stack Overflow");
    }
}

void pop() {
    if (!isEmpty()) {
        printf("%d", s.array[s.top--]);
    }
    else {
        printf("Stack Underflow");
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

int peak() {
    return s.array[s.top];
}

int main() {
    s.top = -1;
    s.capacity = 10;
    int no_of_ele;
    scanf("%d", &no_of_ele);
    for (int i = 0; i < no_of_ele; i++) {
        scanf("%d", &s.array[i]);
    }
    for (int i = 0; i < no_of_ele; i++) {
        printf("%d ", s.array[i]);
    }
    push(40);
    pop();
    pop();
    push(50);
    peak();
    return 0;
}