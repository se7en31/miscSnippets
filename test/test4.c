#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

int main(void)
{
    //cipher text 'aideh'
    //cipher text values, 0, 8, 3, 4,7
    //key = 'test'
    //test values, 19, 4, 18, 19
    //

    string k = "test";
    string c = "aideh";
    int i = strlen(k);
    int j = 0;
    int temptemp = 0;

    for (int h = 0; h < strlen(c); h++)
    {
        temptemp = (k[j % i] - 'a') - (c[h] - 'a');
        printf("%i\n", temptemp);
        j++;
    }
}