#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *next;
} node;

// Global head pointer
node *head = NULL;

// 1. CREATE a new node
node* createNode(int value) {
    node *newNode = (node*)malloc(sizeof(node));
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

// 2. INSERT at the beginning
void insertAtBeginning(int value) {
    node *newNode = createNode(value);
    newNode->next = head;
    head = newNode;
}

// 3. INSERT at the end
void insertAtEnd(int value) {
    node *newNode = createNode(value);

    if (head == NULL) {
        head = newNode;
        return;
    }

    node *temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
}

// 4. DELETE a node by value
void deleteNode(int value) {
    if (head == NULL) return;

    // Special case: deleting the head itself
    if (head->data == value) {
        node *temp = head;
        head = head->next;
        free(temp);
        return;
    }

    node *curr = head;
    while (curr->next != NULL && curr->next->data != value) {
        curr = curr->next;
    }

    if (curr->next != NULL) {
        node *temp = curr->next;
        curr->next = temp->next;
        free(temp);
    }
}

// 5. SEARCH for a value
int search(int value) {
    int position = 0;
    node *temp = head;
    while (temp != NULL) {
        if (temp->data == value)
            return position;
        temp = temp->next;
        position++;
    }
    return -1;
}

// 6. DISPLAY the list
void display(void) {
    node *temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    insertAtEnd(10);
    insertAtEnd(20);
    insertAtBeginning(5);
    display(); // 5 -> 10 -> 20 -> NULL

    printf("Found 10 at position: %d\n", search(10));
    printf("Found 20 at position: %d\n", search(20));
    printf("Found 5 at position: %d\n", search(5));
    printf("Found 15 at position: %d\n", search(15));

    deleteNode(10);
    display(); // 5 -> 20 -> NULL

    return 0;
}
