#include <stdio.h>
#include <cs50.h>

int main(void)
{
    int n;
    do
    {
        n = get_int("Height: ");
    }
    while (n < 0 || n > 23);

    int tc = n + 1; //total chars
    int sp = n - 1; //initial space chars
    int ht = tc - sp; //initial hash chars

    for (int i = 0; i < n; i++) //rows, total chars per row are user input + 1
    {
        for (int j = 0; j < sp; j++) //spaces, spaces start at - 1 of the user input and decrease
        {
            printf(" ");
        }
        sp--;
        for (int k = 0; k < ht; k++) //hashes, hashes start at difference between total chars, and total spaces, and increase.
        {
            printf("#");
        }
        ht++;
        printf("\n");
    }


}