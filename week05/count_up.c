// steve Tan Z5237560
// the program for eads 2 positive integers and prints the integers between them, one per line.
#include <stdio.h>
int main(void) {
    //int the infor.
    int lower_num,upper_num;
    printf("Enter lower: ");
    scanf("%d", &lower_num);
    
    printf("Enter upper: ");
    scanf("%d", &upper_num);
    
    int temp = 0;
    //test if there is no middle number.
    if (upper_num == lower_num + 1) {
        
    } else {
        while(temp <= upper_num) {
            if (lower_num < temp && temp < upper_num) {
                printf("%d\n", temp);
            }
            temp++;
        }
    }

return 0;
}
