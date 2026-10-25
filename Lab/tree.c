#include <stdio.h>
#include <stdlib.h>

typedef struct tree {
    int data;
    struct tree *left;
    struct tree *right;
} node;

node *root = NULL;

node* create_node(int val) {
    node *new_node = (node*)malloc(sizeof(node));
    new_node->data = val;
    new_node->left = NULL;
    new_node->right = NULL;
    return new_node;
}

void add_node(int val) {
    node *new_node = create_node(val);
    if (root==NULL) {
        root = new_node;
    }
    else {
        node *tp = root;
        while (1) {
            if (val < tp->data) {
                if (tp -> left == NULL) {
                    tp -> left = new_node;
                    break;
                }
                tp = tp -> left;
            }
            else if (val > tp->data) {
                if (tp -> right == NULL) {
                    tp -> right = new_node;
                    break;
                }
                tp = tp -> right;
            }
            else {
                printf("Program Terminated");
                break;
            }
        }
    }
}

void intraverse(node *root){
    if(root==NULL)
        return;
    else{
        intraverse(root->left);
        printf("%d ",root->data);
        intraverse(root->right);
    }
}

int main(){
    add_node(40);
    add_node(10);
    add_node(0);
    add_node(30);
    add_node(20);
    add_node(50);
    add_node(90);
    add_node(70);
    add_node(60);
    add_node(15);
    intraverse(root);
    return 0;
}