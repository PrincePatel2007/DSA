#include<stdio.h>

struct Student {
    char name[15];
    int roll_no;
    char address[50];
};

void GET_DETAILS(struct Student *s) {
    printf("Enter student name: ");
    fgets(s->name, 15, stdin);
    printf("Enter Roll No: ");
    scanf("%d", &s->roll_no);
    getchar();
    printf("Enter address: ");
    fgets(s->address, 50, stdin);
    printf("\n");
}

void POST_DETAILS(struct Student *s) {
    printf("Name: %s", s->name);
    printf("Roll no: %d\n", s->roll_no);
    printf("Address: %s\n", s->address);
}

int main() {
    struct Student s1, s2;
    GET_DETAILS(&s1);
    GET_DETAILS(&s2);
    POST_DETAILS(&s1);
    POST_DETAILS(&s2);
    return 0;
}