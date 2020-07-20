//steve TAN z5237560
//Date Oct. 2019
//a programe for reverse number.
#define star 0
#define final 99
#include <stdio.h>
int main(void) {
    int scanned_in_value[100] = {star}, counter = 0; 
    printf("Enter numbers forwards:\n");
    
    
    //scanf the number
    while (counter <= final 
           && scanf("%d", &scanned_in_value[counter]) == 1) {
        
        counter++;

    }
  
    counter--;
    
    //printf them 
    printf("Reversed:\n");
    while (counter >= 0) {
    
        printf("%d\n", scanned_in_value[counter]);
        counter--;
    }
    return 0;
}
