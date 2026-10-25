#include <stdio.h>
#include<ctype.h>
#include<math.h>

#define MAX 20

struct stack{
int top;
int arr[MAX];
};

void push(int num, struct stack *s){
    if(s->top==MAX-1)
        printf("Stack Overflow!!");
    else
        s->arr[++s->top]=num;
    }
void pop(struct stack *s){
    if(s->top==-1)
        printf("Stack Underflow!!");
    else
        s->top--;
}
int main(){
    struct stack s;
    s.top=-1;
    printf("Enter Expression : ");
    char exp[MAX];
    scanf("%s",exp);
    int i=0;

    while(exp[i]!='\0'){
        if(isdigit(exp[i]))
            push(exp[i]-'0', &s);
        else if(exp[i]=='+' && s.top>=1){
            int x =  s.arr[s.top-1] + s.arr[s.top];
            s.top =s.top-2;
            push(x, &s);}
        else if(exp[i]=='-' && s.top>=1){
            int x = s.arr[s.top-1] - s.arr[s.top];
            s.top = s.top-2;
            push(x, &s);}
        else if(exp[i]=='*' && s.top>=1){
            int x = s.arr[s.top-1] * s.arr[s.top];
            s.top = s.top-2;
            push(x, &s);}
        else if(exp[i]=='/' && s.top>=1){
            int x = s.arr[s.top-1] / s.arr[s.top];
            s.top = s.top-2;
            push(x, &s);}
        else if((exp[i]=='$' || exp[i]=='^') && s.top>=1) {
            int x = pow(s.arr[s.top-1],s.arr[s.top]);
            s.top = s.top-2;
            push(x, &s);}
        else
            printf("Expression is not valid!!");
    i++;
    }
    printf("%d",s.arr[s.top]);
    return 0;
}
