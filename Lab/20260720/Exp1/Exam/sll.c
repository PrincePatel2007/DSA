#include<stdio.h>
#include<stdlib.h>

typedef struct sll {
    int data;
    struct sll *next;
} node;

node* head = NULL;

node* create_node(int ele) {
    node* New_node = (node*)malloc(sizeof(node));
    New_node->data = ele;
    New_node->next = NULL;
    return New_node;
}

node* insertAtBeginning(int ele) {
    node* newnode = create_node(ele);
    newnode -> next = head;
    head = newnode;
    return head;
}

node* insertAtEnd(int ele) {
    node* newnode = create_node(ele);
    node* tp = head;
    while (tp->next != NULL) {
        tp = tp->next;
    }
    tp->next = newnode;
    return newnode;
}

node* insertAfter(int ref, int ele) {
    node* newnode = create_node(ele);
    node* tp = head;
    while(tp!=NULL && tp->data!=ref) {
        tp = tp->next;
    }
    if (tp == NULL) {
        printf("Element not found");
        return NULL;
    }
    node* temp = tp -> next;
    tp -> next = newnode;
    newnode -> next = temp;
    return newnode;
}

node* deleteAfter(int ref) {
    node* tp = head;
    while (tp!=NULL && tp->data!=ref) {
        tp = tp ->next;
    }
    if (tp==NULL) {
        printf("Element not found");
        return NULL;
    }
    node* temp = tp -> next;
    tp -> next = temp -> next;
    free(temp);
    return head;
}

void traverse(void) {
    node* tp = head;
    while (tp!=NULL) {
        printf("%d->", tp->data);
        tp = tp->next;
    }
}

int main() {
    insertAtBeginning(10);
    insertAtBeginning(20);
    insertAtBeginning(30);
    insertAtEnd(40);
    insertAtEnd(50);
    insertAfter(10, 70);
    traverse();
    deleteAfter(10);
    printf("\n");
    traverse();
    return 0;
}