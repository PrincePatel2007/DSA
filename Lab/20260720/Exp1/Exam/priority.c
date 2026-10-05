#include<stdio.h>

#define MAX 5

struct Queue {
    int data[MAX];
    int front;
    int rear;
    int priority;
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

void Enqueue(struct Queue *q, int ele, int pr) {
    if (!is_Full(q)) {
        for (int i = q->front; i <= q->rear; i++) {
            if 
        }
    } 
}
