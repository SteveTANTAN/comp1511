// Date Sept. 2019
// steve TAN z5237560
#include<stdio.h>
int main(void) {
    int number_of_sides, number_of_dice;
    double average_value, dice_range1, dice_range2;
    
    printf("Enter the number of sides on your dice:\t");
    scanf("%d", &number_of_sides);
    
    printf("Enter the number of dice being rolled:\t");
    scanf("%d", &number_of_dice);
// input the infor we need.
   
    dice_range1 = 1 * number_of_dice;
    dice_range2 = number_of_dice * number_of_sides;
    average_value = (dice_range1 + dice_range2)/ 2;
//calculate the range we need
    
    if (dice_range2 <= 0) {
        printf("These dice will not produce a range.\n");
    }
    else {
        printf("Your dice range is %.0lf to %.0lf.\n", dice_range1, dice_range2);
        printf("The average value is %.6lf\n", average_value);
    }

 
    return 0;
}
