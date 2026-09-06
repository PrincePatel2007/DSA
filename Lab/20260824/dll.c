#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
    struct node *prev;
};

typedef struct node node;
node *head = NULL;

node *createNode(int val) {
    node *NewNode = (node*)malloc(sizeof(node));
    NewNode -> data = val;
    NewNode -> next = NULL;
    NewNode -> prev = NULL;
    return NewNode;
}

node *insertAtBeginning(int val) {
    if (head != NULL) {
        node *new_node = createNode(val);
        head -> prev = new_node;
        new_node -> next = head;
        head = new_node;
    }
    else {
        head = createNode(val);
    }
    return head;
}

node *insertAtEnd(int val) {
    if (head != NULL) {
        node *tp = head;
        while (tp -> next != NULL) {
            tp = tp -> next;
        }
        node *new_node = createNode(val);
        tp -> next = new_node;
        new_node -> prev = tp;
    }
    else {
        head = createNode(val);
    }
    return head;
}

node *insertAfter(int ref, int val) {
    if (head != NULL) {
        node *new_node = createNode(val);
        node *tp = head;
        while (tp != NULL && tp -> data != ref) {
            tp = tp -> next;
        }
        if (tp -> data == ref) {
            if (tp -> next != NULL) {
                new_node -> next = tp -> next;
                tp -> next -> prev = new_node;
                tp -> next = new_node;
                new_node -> prev = tp;
            }
            else {
                insertAtEnd(val);
            }
        }
        else {
            printf("Key not found");
        }
    }
    else {
        printf("Linked list empty");
    }
    return head;
}

void *deleteAtEnd(void) {
    node *tp = head;
    while (tp -> next -> next != NULL) {
        tp = tp -> next;
    }
    tp -> next = NULL;
}

void *deleteAfter(int ref) {
    if (head != NULL) {
        node *tp = head;
        while (tp != NULL && tp -> data != ref) {
            tp = tp -> next;
        }
        if (tp -> data == ref) {
            if (tp -> next == NULL) {
                printf("Nothing to Delete");
            }
            else {
                if (tp -> next -> next != NULL) {
                    node *temp = tp -> next -> next;
                    tp -> next = temp;
                    temp -> prev = tp;
                }
                else {
                    deleteAtEnd();
                }
            }
        }
        else {
            printf("Key not found");
            }
    }
    else {
        printf("\n Linked list is empty");
    }
}

void traverse(void) {
    node *tp = head;

    while(tp -> next != NULL) {
        printf("%d->", tp -> data);
        tp = tp -> next;
    }
    printf("%d->NULL", tp -> data);
}

int main() {
    insertAtBeginning(7);
    insertAtEnd(14);
    insertAtBeginning(9);
    insertAfter(7, 15);
    insertAfter(14, 13);
    traverse();
    printf("\n");
    deleteAtEnd();
    deleteAfter(7);
    traverse();
    return 0;
}