#include <stdio.h>
struct Student {
    char name[50];
    int roll_no;
    float cgpa;
};
int main() {
    struct Student s = {"Prince Patel", 34, 9.85};
    struct Student *ptr = &s;
    printf("Name: %s\n", ptr->name);
    printf("Roll No : %d\n", ptr->roll_no);
    printf("CGPA: %f\n", ptr->cgpa);
    return 0;
}
