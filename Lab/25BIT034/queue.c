#include <stdio.h>

#define MAX 5

struct queue{
    int arr[5];
    int front,rear;
};
int isempty(struct queue *q) {
    if(q->front == -1)
        return 1;
    return 0;
}
int isfull(struct queue *q) {
    if(q->rear == MAX-1)
        return 1;
    return 0;
}
int enqueue(int a, struct queue *q) {
    if(isfull(q))
        printf("Queue is full!!");
    else if(isempty(q)){
        q->front=0;
        q->arr[++q->rear]=a;}
    else {
        q->arr[++q->rear]=a;
    }
}


int dequeue(struct queue *q) {
    if(isempty(q))
        printf("Queue is  empty!!");
    else if(q->rear == q->front){
        printf("Dequeued element %d \n",q->arr[q->front]);
        q->rear = q->front=-1;
    }
    else {
        printf("Dequeued element %d \n",q->arr[q->front]);
        q->front++;
    }
}
int peek(struct queue *q) {
    if(isempty(q))
        printf("Queue is empty!!");
    else {
        printf("Peek Element = %d",q->arr[q->front]);
    }
}
int traverse(struct queue *q) {
    if (isempty(q)==1)
        printf("Queue is empty!!\n");
    else {
        for(int i = q->front; i <= q->rear; i++){
            printf("%d \n",q->arr[i]);
        }
    }
}
int main(){
    struct queue q;
    q.front=-1;
    q.rear=-1;

    int a,b;
    int flag=0;
    while(flag!=1){
        printf("Which Operation do you want to apply on Queue? \n 1. Enqueue \n 2. Dequeue \n 3. Peek \n 4. Traverse \n 5. Exit \n");
        scanf("%d", &a);
        switch(a){
        case 1:
            printf("Enter element: \n");
            scanf("%d", &b);
            enqueue(b, &q);
            break;
        case 2:
            dequeue(&q);
            break;
        case 3:
            peek(&q);
            break;
        case 4:
            traverse(&q);
            break;
        case 5:
            flag = 1;
            break;
        default:
            printf("ERROR");
            break;
        }
    }

return 0;
}