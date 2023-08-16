#include <cs50.h>
#include <stdio.h>
#include <math.h>

//todo input cc, multiply ever other digit starting from second to last
//sum those individual digits, add to remaining digits.
//check if valid based on ending with a '0', print company it belongs to or invalid.

//Amex - 15 digits, starts with 34 or 37.
//MasterCard - 16 digits, starts with 51, 52, 53, 54, 55
//Visa - 13, or 16 digits, starts with a 4

int main(void)
{
unsigned long long cc_num = 378282246310005;
int counter = 0;
int last;
last = cc_num % 10; //gets last number... move that number into an array? loop and get next end number, into dif array for *2?

while(cc_num > 0)
    {
    cc_num = cc_num / 10;
    counter++;
    }

if (counter < 15 || counter > 16) //need to add check for 13.
    {
        printf("Credit Number Length: %i\n", counter);
        printf("Invalid Credit Card Length\n");
        return 1;
    }

    else
    {
    printf("Counter: %i\n", counter);
    printf("CC: %lli\n", cc_num);
    printf("Last Digit %i\n", last);
    }
}