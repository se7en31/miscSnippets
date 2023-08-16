#include <cs50.h>
#include <stdio.h>
//#include <stdlib.h>
#include <ctype.h>
#include <string.h>

bool verify(string key);
int main(int argc, string argv[])
{
    string k = argv[argc - 1]; //k is key value
    int len = strlen(k);    //length of string, to use as MOD number.
    int j = 0;
    if (argc != 2) //check for no command line arguement, or too many.
    //get key value k[j % len] - 'A' to get alpha index., get cipher value c[i] - 'A' find the difference in values
    {
        printf("Usage: ./decrypt k\n");
        return 1;
    }
    else if (!verify(k))
    {
        printf("Usage: ./decrypt k\n");
        return 1;
    }
    else
    {
        string c = get_string("ciphertext: "); //set plaintext soon to be ciphertext
        int temp = 0;
        printf("Decrypted: ");
        for (int i = 0, l = strlen(c); i < l; i++)
        {
            if (isalpha(c[i]))
            {
                if (isupper(c[i]))
                {
                    temp = toupper(c[i] - 'A') - toupper(k[j % len] - 'A') + 'A';
                    if (temp < 0)
                    {
                        temp = 26 + temp + 'A';
                    }
                    printf("%c", temp);
                    j++;
                }
                else
                {
                    temp = tolower(c[i] - 'a') - tolower(k[j % len] - 'a') + 'a';
                    if (temp < 0)
                    {
                        temp = 26 + temp + 'a';
                    }
                    if (temp < 'a') // I DONT KNOW WHY  I HAVE TO DO THIS PART, BUT I HAD TO, TO MAKE IT WORK
                    {
                        temp = temp + 26;
                    }
                    printf("%c", temp);
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