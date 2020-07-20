//steve Tan z5237560    
//Date 01/11/2019
#include<stdio.h>
#define MAX 4096

int main(void) {
     
    printf("Enter a string: ");
    char ch[MAX];
    int counter = 0; 
    fgets(ch, MAX, stdin);
    
    while (ch[counter] != '\0') {
        counter++;
    }
    counter = counter - 2;
    
    
  
    
    
    int test = 1;
    int i = 0, m = counter;
    while (i <= counter) {
        if (ch[i] == ch[m]) {
            test = test * 1;    
        
        } else {
            test = test * 0;
        }
        m--;
        i++;
    }
    
    if (test == 0) {
        printf("String is not a palindrome\n");
    
    } else {
        printf("String is a palindrome\n");
    }
    
    
    
    return 0;
}
