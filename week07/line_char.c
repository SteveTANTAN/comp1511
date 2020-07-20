//Steve Tan z5237560
//Date 04/11/2019
#define MAXNUM  256
#include<stdio.h>
int main (void) {
    char ch [MAXNUM];
    fgets(ch, MAXNUM, stdin);
    
    int temp;
    scanf("%d", &temp);
    printf("The character in position %d is '%c'\n", temp, ch[temp]);
    return 0;
}
