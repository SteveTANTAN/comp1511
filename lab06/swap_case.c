//5237560 Steve TAN
//reads characters from its input and writes the same characters to 
//its output with lower case letters converted to upper case 
//and upper case letters converted to lower case
#include <stdio.h>
void swap_case(int character);
int main(void) {
    int ch = getchar ();
    while (ch != EOF) {
        swap_case(ch);
        
        
        ch = getchar ();
    }
    


    return 0;
}
//the fuction used for transforming.
void swap_case(int character) {
    if (character >= 65 && character <= 122 ) {
        if (character >= 'A' && character <= 'Z') {
            putchar(character - 'A'+'a');
        } else if (character >= 'a' && character <= 'z') {
            putchar(character -'a'+'A');
        }
                
    } else {
        putchar (character);
    }
   
}
