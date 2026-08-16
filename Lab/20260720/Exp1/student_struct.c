#include<stdio.h>

// Code unprofessional

struct Student {
    char name[50];
    int roll_no;
    char address[150];
};

int main() {
    int len = 5;

    struct Student s[len];

    for (int i=0; i<len; i++) {
        printf("\nEnter Student %d details: \n", i+1);
        printf("Enter Student name: ");
        fgets(s[i].name, sizeof(s[i].name), stdin);
        printf("Enter Roll no (int only): ");
        scanf("%d", &s[i].roll_no);
        scanf("%*c");
        printf("Enter Address: ");
        fgets(s[i].address, sizeof(s[i].address), stdin);
    }

    for (int i=0; i<len; i++) {
        printf("\nStudent %d details:- \n Name:    %s  Roll no: %d \n Address: %s \n", i+1, s[i].name, s[i].roll_no, s[i].address);
    }
    return 0;

}
