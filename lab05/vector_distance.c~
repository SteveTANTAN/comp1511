// COMP1511 Week 5 Lab
//
// This program was written by Steve Tan z5237560
// on 17/10/2019
#include <stdio.h>
#include <math.h> 
double Euclidean_distance(int array1[], int array2[],int leng);
int main(void) {
        
    int length;
    printf("Enter vector length: ");
    scanf("%d", &length);
    
    printf("Enter vector 1: ");
    int vector_1[length];
    int i=0;
    while (i < length){
        scanf("%d", &vector_1[i]);
        i++;
    }
    
    printf("Enter vector 2: ");
    int vector_2[length];
    int u=0;
    while (u < length){
        scanf("%d", &vector_2[u]);
        u++;
    }
    printf("Euclidean distance =  %lf\n", Euclidean_distance(vector_1, vector_2,length));   
    
    return 0;
}


double Euclidean_distance(int array1[], int array2[],int leng) {
    int temp=0;
    double sum=0;
    while (temp < leng) {
        sum = sum + (array1[temp]-array2[temp])*(array1[temp]-array2[temp]);   
        temp++;
    }
    double dis;
    dis = sqrt(sum);
    return (dis);
    
}
