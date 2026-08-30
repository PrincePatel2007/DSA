#include <stdio.h>

#define MAX 10

struct Queue {
    int info[MAX];
    int front;
    int rear;
};

void init(struct Queue *q) {
    q->front = -1;
    q->rear = -1;
}

int is_full(struct Queue *q) {
    return (q->front == (q->rear + 1) % MAX);
}

int is_empty(struct Queue *q) {
    return (q->front == -1);
}

void enqueue(int ele, struct Queue *q) {
    if (is_full(q)) {
        printf("The Queue is Full\n");
        return;
    }
    if (is_empty(q)) {
        q->front = 0;
        q->rear = 0;
    } else {
        q->rear = (q->rear + 1) % MAX;
    }
    q->info[q->rear] = ele;
}

void dequeue(struct Queue *q) {
    if (is_empty(q)) {
        printf("Queue already empty\n");
        return;
    }
    if (q->front == q->rear) {
        // Last element removed; reset queue
        q->front = -1;
        q->rear = -1;
    } else {
        printf("%d\n", q->info[q->front]);
        q->front = (q->front + 1) % MAX;

    }
}

void traverse(struct Queue *q) {
    if (is_empty(q)) {
        printf("Queue is empty\n");
        return;
    }
    int i = q->front;
    while (1) {
        printf("%d ", q->info[i]);
        if (i == q->rear) break;
        i = (i + 1) % MAX;
    }
    printf("\n");
}

int main() {
    struct Queue q1;
    init(&q1);

    enqueue(9, &q1);
    enqueue(7, &q1);
    enqueue(4, &q1);
    enqueue(5, &q1);
    enqueue(6, &q1);
    enqueue(0, &q1);
    enqueue(1, &q1);
    enqueue(2, &q1);
    enqueue(3, &q1);

    traverse(&q1);
    dequeue(&q1);
    traverse(&q1);

    return 0;
}
