//steve tan z5237560
//Date oct 26
#define max_size 100

#include<stdio.h>
int trans(char array[max_size], int character);

int main(void) {
    char array[max_size];
    //input the infor we need,
    fgets(array, max_size, stdin);
    
    int character = getchar ();
    while (character != EOF) {
        putchar (trans(array, character));
        
        
        character = getchar ();
    }
    return 0; 
}

int  trans(char array[max_size], int character) {
    //for lower word.
    int result = 0;
 
   
    if (character >= 'a' && character <= 'z') {
        result = array [character - 'a'];
             
    //for upper word
            
    } else if (character >= 'A' && character <= 'Z') {
        int counter2 = character - 'A';
            
        result = array[counter2] - 'a' + 'A';
    } else {
        result = character; 
    }
        

    return result;
}
