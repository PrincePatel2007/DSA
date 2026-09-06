#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

typedef struct node node;
node *head = NULL;

node *createNode(int val) {
    node *NewNode = (node*)malloc(sizeof(node));
    NewNode -> data = val;
    NewNode -> next = NULL;
    return NewNode;
}

node *insertAtBeginning(int val) {
    node *new_node = createNode(val);
    if (head != NULL) {
        new_node -> next = head;
        node *tp = head;
        while (tp -> next != head) {
            tp = tp -> next;
        }
        head = new_node;
        tp -> next = head;
    }
    else {
        head = new_node;
        head -> next = head;
    }
}


void traverse(void) {
    node *tp = head;
    while (tp -> next != head) {
        printf("%d->", tp -> data);
        tp = tp -> next;
    }
    printf("%d->HEAD", tp -> data);
}

int main() {
    insertAtBeginning(7);
    insertAtBeginning(4);
    insertAtBeginning(5);
    traverse();
    return 0;
}

