#include <stdio.h>

char to_lowercase(char c){
    return c + 32; // convert to lowercase   
}


int main() {
    char c;
    printf("Enter a character: ");
    scanf("%c", &c);

    if (c >= 'A' && c <= 'Z') {
        c = to_lowercase(c);
        printf("ASCII value of %c = %d", c, c);
    } else if (c >= 'a' && c <= 'z') {
        printf("character is allready a lowercase letter\n");
        printf("ASCII value of %c = %d", c, c);
    } else {
        printf("entered character is not a letter\n");
        printf("ASCII value of %c = %d", c, c);
    }    
    return 0;
}