// COMP1511 Week 5 Lab: Circle Facts
//
// This program was written by Steve Tan z5237560
// on 17/10/2019
//
// This program prints out facts about a circle given its radius,
// using functions.
//

#include <stdio.h>
#include <math.h>

double area(double radius);
double circumference(double radius);
double diameter(double radius);


int main(void) {
    double radius;

    printf("Enter circle radius: ");
    scanf("%lf", &radius);

    printf("Area          = %lf\n", area(radius));
    printf("Circumference = %lf\n", circumference(radius));
    printf("Diameter      = %lf\n", diameter(radius));

    return 0;
}


// Calculate the area of a circle, given its radius.
double area(double radius) {
    double aRea = M_PI* radius*radius;
    
    return (aRea); 
}

// Calculate the circumference of a circle, given its radius.
double circumference(double radius) {
    double cir = 2* M_PI * radius; 
    
    return (cir); 
}

// Calculate the diameter of a circle, given its radius.
double diameter(double radius) {
    double dia =2 * radius; 
    
    return (dia);
}
