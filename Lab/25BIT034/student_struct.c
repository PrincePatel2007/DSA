#include <stdio.h>

struct Student {
    char name[20];
    int roll_no;
    char address[50];
};

void post_details (struct Student *s) {
    printf("\nEnter name: ");
    fgets(s->name, 20, stdin);
    printf("Enter Roll No: ");
    scanf("%d", &s->roll_no);
    getchar();
    printf("Enter address: ");
    fgets(s->address, 50, stdin);
} 

void get_details (struct Student *s) {
    printf("\nName: %s", s->name);
    printf("Roll No: %d", s->roll_no);
    printf("\nAddress: %s", s->address);
} 

int main() {
    struct Student s1, s2, s3;
    post_details(&s1);
    post_details(&s2);
    post_details(&s3);
    printf("\nDetails of Students:\n");
    get_details(&s1);
    get_details(&s2);
    get_details(&s3);
    return 0;
}


