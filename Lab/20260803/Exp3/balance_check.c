#include <stdio.h>
#include <string.h>

struct Stack {
    int top;
    char arr[50];
    char input_str[50];
};

void initialize(struct Stack *s) {
    s->top = -1;
}

int is_empty(struct Stack *s) {
    if (s->top==-1) {
        return 1;
    }
    else {
        return 0;
    }
}

void neutralize(struct Stack *s) {
    for (int i = 0; i < strlen(s->input_str); i++) {
        if (!is_empty(s) && (((s->input_str[i]== ')') && (s->arr[s->top])=='(') || ((s->input_str[i]== ']') && (s->arr[s->top])=='[') || ((s->input_str[i]== '}') && (s->arr[s->top])=='{'))) {
            (s->top)--;
        }
        else {
            s->arr[++s->top] = s->input_str[i];
        }
    }
}

int is_balanced(struct Stack *s) {
    initialize(s);
    neutralize(s);
    if (is_empty(s)==1) {
        printf("%s is Balanced", s->input_str);
        return 1;
    }
    else {
        printf("%s is unbalanced", s->input_str);
        return 0;
    }
}

int main() {
    struct Stack s1;
    initialize(&s1);
    printf("Enter string: ");
    scanf("%s", s1.input_str);
    is_balanced(&s1);
    return 0;
}