//steve tan z5237560
//Date oct 26
#define MAX_SIZE 100

#include<stdio.h>
int trans(char array[MAX_SIZE], int character);

int main(void) {
    char array[MAX_SIZE];
    //input the infor we need,
    fgets(array, MAX_SIZE, stdin);
    
    int character = getchar ();
    while (character != EOF) {
        putchar (trans(array, character));
        
        
        character = getchar ();
    }
    return 0; 
}

int  trans(char array[MAX_SIZE], int character) {
    //for lower word.
    int result = 0;
 
   
    if (character >= 'a' && character <= 'z') {
        int i = 0;
        while (array[i] != '\0') {
            if (array[i] == character) {
                result = i + 'a';
            }
            i++;        
        }
             
    //for upper word        
    } else if (character >= 'A' && character <= 'Z') {
        character = character - 'A' + 'a';
        int i = 0;
        while (array[i] != '\0') {
            if (array[i] == character) {
                result = i + 'A';
            }
            i++;        
        }
            
        
    } else {
        result = character; 
    }
        

    return result;
}
