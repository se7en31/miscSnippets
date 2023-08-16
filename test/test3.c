#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

int main(void)
{
    string k = "hello";
    int i = strlen(k);
    int j = 0;

    for (int h = 0; h < 10; h++)
    {
        printf("%c\n", k[j % i]);
        j++;
    }
}