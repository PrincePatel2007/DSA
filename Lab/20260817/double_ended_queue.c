#include <stdio.h>
struct queue{
    int rear, front;
    int arr[20];};
struct queue q;
int isfull(){
    if(q.rear==19)
        return 1;
    return 0;
}
int isempty(){
    if(q.front==-1)
        return 1;
    return 0;
}
int enqueue_rear(int a){
    if(isfull())
        printf("QUEUE IS FULL!!\n");
    else if(isempty()){
        q.rear=q.front=0;
        q.arr[q.rear]=a;}
    else{
        q.arr[++q.rear]=a;
    }}
int dequeue_front(){
    if(isempty())
        printf("QUEUE IS EMPTY!!\n");
    if(q.rear==q.front){
        printf("Dequeued element %d \n",q.arr[q.rear]);
        q.rear=q.front=-1;}
    else{
        printf("Dequeued element %d \n",q.arr[q.front]);
        q.front++;
    }
}
int enqueue_front(int a){
    if(q.front==0)
        printf("ENQUEUE FROM FRONT NOT POSSIBLE!!\n");
    else if(isempty()){
        q.rear=q.front=0;
        q.arr[q.rear]=a;}
    else{
        q.arr[--q.front]=a;
    }}
int dequeue_rear(){
    if(isempty())
        printf("QUEUE IS EMPTY!!\n");
    if(q.rear==q.front){
        printf("Dequeued element %d \n",q.arr[q.rear]);
        q.rear=q.front=-1;}
    else{
        printf("Dequeued element %d \n",q.arr[q.rear]);
        q.rear--;
    }
}
int traverse(){
    if (isempty()==1)
        printf("Queue is empty!!\n");
    else {
        for(int i=q.front;i<=q.rear;i++){
            printf("%d, ",q.arr[i]);}
        printf("\n");}}
int main(){
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
            enqueue_rear(a);
            break;
        case 2:
            dequeue_rear();
            break;
        case 3:
            printf("Enter Element: ");
            scanf("%d",&a);
            enqueue_front(a);
            break;
        case 4:
            dequeue_front();
            break;
        case 5:
            traverse();
            break;
        case 6:
            flag=1;
            break;
            }}
    return 0;
}