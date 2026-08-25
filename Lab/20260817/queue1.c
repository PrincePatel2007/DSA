#include <stdio.h>

#define MAX 10
struct Queue {
    int info[MAX];
    int front;
    int rear;
};

int is_full(struct Queue *q) {
    if (q->front % MAX==(q->rear+1) % MAX) {
        return 1;
    }
    else {
        return 0;
    }
}

int is_empty(struct Queue *q) {
    if (q->front==-1) {
        return 1;
    }
    else {
        return 0;
    }
}

void enqueue(int ele, struct Queue *q) {
    if (is_empty) {
        q->front = 0;
    }
    if (!is_full) {
        q->info[++q->rear % MAX] = ele;
    }
    else {
        printf("The Queue is Full");
    }
}

void dequeue (struct Queue *q) {
    if (!is_empty) {
        q->info[q->front++ % MAX] = NULL;
    }
    else {
        printf("Queue already empty");
    }
}

void traverse (struct Queue *q) {
    int i = q->front % MAX;
    while (i != q->rear % MAX)
}