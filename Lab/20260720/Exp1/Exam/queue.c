#include<stdio.h>

#define MAX 5

struct Queue {
    int data[MAX];
    int front;
    int rear;
};

int is_Full(struct Queue *q) {
    if (q->rear == MAX - 1) {
        return 1;
    }
    else {
        return 0;
    }
}

int is_Empty(struct Queue *q) {
    if (q->front == -1) {
        return 1;
    }
    else {
        return 0;
    }
}

void enqueue(struct Queue *q, int ele) {
    if (is_Empty(q)) {
        q->front = 0;
    }

    if (!is_Full(q)) {
        q->data[++q->rear] = ele;
        printf("\nEnqued: %d", ele);
    }
    else {
        printf("\nQueue is full");
    }
}

void dequeue(struct Queue *q) {
    if (!is_Empty(q)) {
        printf("\nDequed: %d", q->data[q->front]);
        if (q->front == q->rear) {
            q-> front = -1;
            q-> rear = -1;
        }
        else {
            q->front++;
        }
    }
    else {
        printf("\nQueue is empty");
    }
}

void peek(struct Queue *q) {
    printf("\nPeek: %d", q->data[q->front]);
}

int main() {
    struct Queue q;
    q.front = -1;
    q.rear = -1;
    dequeue(&q);
    enqueue(&q, 7);
    enqueue(&q, 4);
    enqueue(&q, 3);
    enqueue(&q, 5);
    peek(&q);
    dequeue(&q);
    dequeue(&q);
    peek(&q);
    enqueue(&q, 6);
    peek(&q);
    dequeue(&q);
    dequeue(&q);
    dequeue(&q);
    dequeue(&q);
    enqueue(&q, 9);
    peek(&q);
    return 0;
}