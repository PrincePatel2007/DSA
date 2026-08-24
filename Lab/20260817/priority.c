#include<stdio.h>
struct Queue{
    int arr[20];
    int priority[20];
    int front, rear;
    };
struct Queue q;
int isEmpty();
int isFull();
void enqueue(int newele,int pr);
void dequeue();
void peek();
void traverse();
int main(){
    int newele,pr,a,n=0;
    q.front=-1;
    q.rear=-1;
    while(n==0){
        printf("What Queue operations do you want to perform??\n1.ENQUEUE\n2.DEQUEUE\n3.PEEK\n4.TRAVERSE\n5.EXIT\n");
        scanf("%d",&a);
        switch(a){
            case 1:
                printf("Enter element: ");
                scanf("%d",&newele);
                printf("Enter its priority: ");
                scanf("%d",&pr);
                enqueue(newele,pr);
                break;
            case 2:
                dequeue();
                break;
            case 3:
                peek();
                break;
            case 4:
                traverse();
                break;
            case 5:
                n=1;
                break;
            default:
                printf("INVALID INPUT!!\n");
                break;
        }
    }
    return 0;
}
int isEmpty(){
    if(q.front==-1)
        return 1;
    return 0;
}
int isFull(){
    if(q.rear==19)
        return 1;
    return 0;
}
void enqueue(int newele, int pr){
    if(isFull())
        printf("The Queue is Full!!\n");
    else if(isEmpty()){
        q.front=0;
        q.rear=0;
        q.arr[q.rear] = newele;
        q.priority[q.rear] = pr;
    }
    else {
        int i;
        for(i=q.rear;i>=q.front;i--) {
            if(pr<q.priority[i]){
                q.arr[i+1]=q.arr[i];
                q.priority[i+1]=q.priority[i];}
            else
                break;
        }
        q.arr[i+1] = newele;
        q.priority[i+1] = pr;
        q.rear++;
    }
}
void dequeue(){
    if(isEmpty())
        printf("The Queue is Empty!!\n");
    else if(q.rear==q.front){
        printf("Dequeued element is: %d (Priority: %d)\n", q.arr[q.front], q.priority[q.front]);
        q.front=-1;
        q.rear=-1;
    }
    else{
        printf("Dequeued element is: %d (Priority: %d)\n", q.arr[q.front], q.priority[q.front]);
        q.front++;}
}
void peek(){
    if(isEmpty())
        printf("The Queue is Empty!!\n");
    else
        printf("The highest priority element is: %d (Priority: %d)\n", q.arr[q.front], q.priority[q.front]);
}
void traverse(){
    if(isEmpty())
        printf("The Queue is Empty!!\n");
    else {
        printf("The queue elements with priorities are:\n");
        for(int i=q.front;i<=q.rear;i++)
            printf("%d[%d]\n", q.arr[i], q.priority[i]);
    }
}