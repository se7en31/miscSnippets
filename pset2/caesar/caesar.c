#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

//isalpha, isupper, islower <ctype.h> boolean ifs
//if (isupper('Z')) { stuff }
//c[i] = (p[i] + k) % 26
//strlen(c), forloop over length, to go through each letter. c[0], c[1], etc

int main(int argc, string argv[])
{
    int k = atoi(argv[argc - 1]); //k is key value

    if (argc != 2) //check for no command line arguement, or too many.
    {
        printf("Usage: ./caesar k");
        return 1;
    }
    else if (k < 0) //check to see if arguement is a positive number.
    {
        printf("Usage: ./caesar k");
        return 1;
    }
    else
    {
        string c = get_string("plaintext: "); //set plaintext soon to be ciphertext
        printf("ciphertext: ");
        for (int i = 0, l = strlen(c); i < l; i++)
        {
            if (isalpha(c[i]))
            {
                if (isupper(c[i]))
                {
                    printf("%c", (c[i] - 'A' + k) % 26 + 'A');
                }
                if (islower(c[i]))
                {
                    printf("%c", (c[i] - 'a'  + k) % 26 + 'a');
                }
            }
            else
            {
                printf("%c", c[i]);
            }
        }
        printf("\n");
    }
}