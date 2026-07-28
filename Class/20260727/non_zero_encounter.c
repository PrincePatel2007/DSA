#include<stdio.h>
int main () {
    int arr[4][5] = {{0,0,3,4,0},{2,1,0,0,0},{0,0,1,0,6},{0,0,4,5,0}};
    int non_zero_len = 0;
    for (int i=0; i<4; i++) {
      for (int j=0; j<5; j++) {
        if (arr[i][j]!=0) {
          non_zero_len+=1;
        }
      }
    }
    int filtered_arr[non_zero_len][3];
    int count=0;
    for (int i=0; i<4; i++) {
      for (int j=0; j<5; j++) {
        if (arr[i][j]!=0) {
          filtered_arr[count][0] = arr[i][j];
          filtered_arr[count][1] = i;
          filtered_arr[count][2] = j;
          count++;
        }
      }
    }

    printf("Value  Row  Column");
    for (int i=0; i<non_zero_len; i++) {
      printf("\n");
      for (int j=0; j<3; j++) {
        printf("  %d   ", filtered_arr[i][j]);
      }
    }

    return 0;
}
