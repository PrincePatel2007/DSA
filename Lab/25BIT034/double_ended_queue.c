#include <stdio.h>

struct queue{
    int rear, front;
    int arr[20];
};

int isfull(struct queue *q){
    if(q->rear==19)
        return 1;
    return 0;
}
int isempty(struct queue *q){
    if(q->front==-1)
        return 1;
    return 0;
}
int enqueue_rear(int a, struct queue *q){
    if(isfull(q))
        printf("QUEUE IS FULL!!\n");
    else if(isempty(q)){
        q->rear=q->front=0;
        q->arr[q->rear]=a;}
    else{
        q->arr[++q->rear]=a;
    }
}
int dequeue_front(struct queue *q){
    if(isempty(q))
        printf("QUEUE IS EMPTY!!\n");
    if(q->rear==q->front){
        printf("Dequeued element %d \n",q->arr[q->rear]);
        q->rear=q->front=-1;}
    else{
        printf("Dequeued element %d \n",q->arr[q->front]);
        q->front++;
    }
}
int enqueue_front(int a, struct queue *q){
    if(q->front==0)
        printf("ENQUEUE FROM FRONT NOT POSSIBLE!!\n");
    else if(isempty(q)){
        q->rear=q->front=0;
        q->arr[q->rear]=a;}
    else{
        q->arr[--q->front]=a;
    }
}
int dequeue_rear(struct queue *q){
    if(isempty(q))
        printf("QUEUE IS EMPTY!!\n");
    if(q->rear==q->front){
        printf("Dequeued element %d \n",q->arr[q->rear]);
        q->rear=q->front=-1;}
    else{
        printf("Dequeued element %d \n",q->arr[q->rear]);
        q->rear--;
    }
}
int traverse(struct queue *q){
    if (isempty(q)==1)
        printf("Queue is empty!!\n");
    else {
        for(int i=q->front;i<=q->rear;i++){
            printf("%d, ",q->arr[i]);}
        printf("\n");}}
int main(){
    struct queue q;
    q.rear=q.front=-1;
    int flag=0;
    int b,a;
    while(flag!=1){
        printf("What operation do you want to perform?? \n 1.Enqueue from end \n 2. Dequeue from end \n 3. Enqueue from front \n 4. Dequeue from front \n 5. Traverse \n 6. EXIT \n");
        scanf("%d",&b);
        switch(b){
            case 1:
                printf("Enter Element: ");
                scanf("%d",&a);
                enqueue_rear(a, &q);
                break;
            case 2:
                dequeue_rear(&q);
                break;
            case 3:
                printf("Enter Element: ");
                scanf("%d",&a);
                enqueue_front(a, &q);
                break;
            case 4:
                dequeue_front(&q);
                break;
            case 5:
                traverse(&q);
                break;
            case 6:
                flag=1;
                break;
        }
    }
    return 0;
}