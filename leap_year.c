#include <stdio.h>
#include <stdint.h>




int main() {
    int year;
    printf("Please enter a year to check if its a leap year: ");
    scanf("%d", &year);

    if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0 ){
        printf("year is a leapyear");
    } else {
        printf("Year is not a leap year:");
    }
    return 0;
}