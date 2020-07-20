// Steve Tan z5237560
//Date Oct. 2019
//lab02 countdown
#include<stdio.h>
int main(void) {
    //initialise counter from 10
    int counter = 10;
    // loop until not >= 0
    while (counter >= 0) {
        // print counter
        printf("%d\n", counter);
        // increment counter
        counter = counter - 1;
    }
    return 0;
}

