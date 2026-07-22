#include<stdio.h>

struct Student {
    char name[50];
    int roll_no;
    char address[150];
};

int main() {
    struct Student s[5];

    for (int i=0; i<5; i++) {
        printf("Enter Student %d details: \n", i+1);
        printf("Enter Student name: ");
        scanf(" %[^\n]", s[i].name);  //To allow space character work properly
        printf("Enter Roll no (int only): ");
        scanf("%d", &s[i].roll_no);
        printf("Enter Address: ");
        scanf(" %[^\n]", s[i].address);  //To allow space character work properly
    }

    for (int i=0; i<5; i++) {
        printf("Student %d details:- \n Name:    %s \n Roll no: %d \n Address: %s \n", i+1, s[i].name, s[i].roll_no, s[i].address);
    }
    return 0;

}