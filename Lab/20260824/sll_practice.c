#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node *next;
};

typedef struct node node;

node *head = NULL;

node* createNode(int val) {
    node *newNode = (node*)malloc(sizeof(node));
    newNode->data = val;
    newNode->next = NULL;
}

void insertAtBeginning(int val) {
    node *newNode = createNode(val);
    newNode->next = head;
    head = newNode;
}

void insertAtEnd(int val) {
    node *newNode = createNode(val);

    if (head!=NULL){
        node *tp = head;
        while (tp->next!=NULL) {
            tp = tp->next;
        }
        tp->next = newNode;
    }
    else {
        head = newNode;
    }
}

int search(int val) {
    node *tp = head;
    int pos = 0;
    while (tp != NULL) {
        if (tp->data == val) {
            return pos;
        }
        tp = tp->next;
        pos++;
    }
    return -1;
}