#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

//isalpha, isupper, islower <ctype.h> boolean ifs
//if (isupper('Z')) { stuff }
//C[i] = (P[i] + K[j]) % 26
//strlen(c), forloop over length, to go through each letter. c[0], c[1], etc

bool verify(string key);
int main(int argc, string argv[])
{
    string k = argv[argc - 1]; //k is key value
    int len = strlen(k);    //length of string, to use as MOD number.
    int j = 0;
    if (argc != 2) //check for no command line arguement, or too many.
    {
        printf("Usage: ./vigenere k\n");
        return 1;
    }
    else if (!verify(k))
    {
        printf("Usage: ./vigenere k\n");
        return 1;
    }
    else
    {
        string c = get_string("plaintext: "); //set plaintext soon to be ciphertext
        int temp = 0;
        printf("ciphertext: ");
        for (int i = 0, l = strlen(c); i < l; i++)
        {
            if (isalpha(c[i]))
            {
                if (isupper(c[i]))
                {
                    temp = toupper(k[j % len]) - 'A';
                    printf("%c", (c[i] - 'A' + temp) % 26 + 'A');
                    j++;
                }
                if (islower(c[i]))
                {
                    temp = tolower(k[j % len]) - 'a';
                    printf("%c", (c[i] - 'a'  + temp) % 26 + 'a');
                    j++;
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

bool verify(string key)
{
    for (int i = 0; i < strlen(key); i++)
    {
        if (!isalpha(key[i]))
        {
            return false;
        }
    }
    return true;
}