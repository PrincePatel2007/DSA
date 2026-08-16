#include <stdio.h>
void swap_values(int *num1,int *num2){
    int temp;
    temp = *num1;
    *num1 = *num2;
    *num2 = temp;
    printf("A= %d\n", *num1);
    printf("B= %d\n", *num2);
}
int main(){
    int a, b;
    printf("A= ");
    scanf("%d",&a);
    printf("B= ");
    scanf("%d",&b);
    int *ptr1 = &a;
    int *ptr2 = &b;
    swap_values(ptr1, ptr2);
    return 0;
    }
