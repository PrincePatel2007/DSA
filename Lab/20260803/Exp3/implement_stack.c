#include <stdio.h>

#define MAX 10

struct Stack {
    int top;
    int capacity;
    int array[MAX];
};

int isEmpty(struct Stack *s) {
    if (s->top == -1) {
        return 1;
    }
    else {
        return 0;
    }
    }

int isFull(struct Stack *s) {
    if (s->top == s->capacity - 1) {
        return 1;
    }
    else {
        return 0;
    }
}

void push(int ele, struct Stack *s) {
    if (!isFull(s)) {
        s->array[++s->top] = ele;
    }
    else {
        printf("\nStack Overflow");
    }
}

void pop(struct Stack *s) {
    if (!isEmpty(s)) {
        printf("\nPopped element is : %d", s->array[s->top--]);
    }
    else {
        printf("\nStack Underflow");
    }
}

void peak(struct Stack *s) {
    printf("\nPeak : %d", s->array[s->top]);
}

void traverse(struct Stack *s) {
    for (int i = s->top - 1; i <= 0; i--) {
        printf("%d", s->array[s->top]);
    }
}

int main() {
    struct Stack stack1;
    stack1.top = -1;
    stack1.capacity = MAX;
    printf("Max capacity of Stack here is 10\n\n");
    int exit = 0;
    do {
        printf("\n\nOptions available are:-\n1. Push\n2. Pop\n3. Peak\n4. Traverse\n5. Exit\n\n");
        int choice;
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter element to push: ");
                int num;
                scanf("%d", &num);
                push(num, &stack1);
                break;
            case 2:
                pop(&stack1);
                break;
            case 3:
                peak(&stack1);
                break;
            case 4:
                traverse(&stack1);
                break;
            case 5:
                exit = 1;
                break;
        }
    } while (exit!=1);
    return 0;
}
