//steve Tan z5237560
//Date Oct. 2019
#include <stdio.h>
int main(void) {
    double totalNumber, marksAwarded;
    double percentage;
    //define the variable.
    printf("Enter the total number of marks in the exam: ");
    scanf("%lf", &totalNumber);
    printf("Enter the number of marks the student was awarded: ");
    scanf("%lf", &marksAwarded);
    //input the information.
    
    percentage = (marksAwarded / totalNumber) * 100;
    //calculate the percentage.
    printf("The student scored %.0lf%% in this exam.\n", percentage);
    
    return 0;
    
}
