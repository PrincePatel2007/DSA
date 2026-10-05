#include<stdio.h>

#define MAX 5

struct Queue {
    int data[MAX];
    int front;
    int rear;
};

int is_Empty(struct Queue *q) {
    if (q->front == -1) {
        return 1;
    }
    else {
        return 0;
    }
}

int is_Full(struct Queue *q) {
    if (q->front % MAX == (q->rear + 1) % MAX) {
        return 1;
    }
    else {
        return 0;
    }
}

void enqueue(struct Queue *q, int ele) {
    if (!is_Full(q)) {
        q->data[++q->rear % MAX] = ele;
        printf("Enqueud: %d", ele);
    }
    else {
        printf("Queue is full");
    }
}

void dequeue(struct Queue *q) {
    if (!is_Empty(q)) {
        printf("Dequed: %d", q->data[q->front%MAX]);
        if (q->front == q->rear) {
            q->front = -1;
            q->rear = -1;
        }
        else {
            q->front++;
        }
    }
    else {
        ("Queue is empty");
    }
}

void traverse(struct Queue *q) {
    for (int i = q->front; i = q->rear ; i++) {
        printf("%d", i%MAX);
    }
}
