// https://gist.github.com/KRount75/c15268a4c1edacee3bacf0b8fa536863
// Kendall Corrected and finished my original decrypt code.
//                  Devon Crawford(se7en31)
/*      Decrypts text using vigenere method         *
*               Kendall Rountree                    *
*                  06/29/2018                       */

#include <cs50.h>
#include <stdio.h>
//#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define key argv[1]

bool verify(char* input);
int main(int argc, string argv[])
{
    int len = strlen(key);    // Length of key, to loop using modulus
    int j = 0; // Tracks looping in presence of non-alphabetic characters
    if (argc != 2 || !verify(key)) // Check for invalid command-line arguments
    {
        printf("Usage: ./decrypt k\n");
        return 1;
    }

    char* c = get_string("Ciphertext: "); // Prompts user to enter plaintext
    int temp = 0; // Stores encrypted value to be printed
    printf("Plaintext: ");
    for (int i = 0, l = strlen(c); i < l; i++)
    {
        if (isalpha(c[i]))
        {
            if (isupper(c[i]))
            {
                temp = (c[i] - 'A') - (toupper(key[j % len]) - 'A');
                if (temp < 0)
                {
                    // Add 1 for looping through 'A'
                    temp = 'Z' - (abs(temp)) + 1;
                }
                else
                {
                    temp = 'A' + abs(temp);
                }
                printf("%c", temp);
                j++;
            }
            else
            {
                temp = (c[i] - 'a') - (tolower(key[j % len]) - 'a');
                if (temp < 0)
                {
                    // Add 1 for looping through 'A'
                    temp = 'z' - (abs(temp)) + 1;
                }
                else
                {
                    temp = 'a' + abs(temp);
                }
                printf("%c", temp);
                j++;
            }
        }
        else // If current plaintext character is non-alphabetic
        {
            printf("%c", c[i]);
        }

    } // End bracket for loop

    printf("\n");
}

bool verify(char* input)
{
    for (int i = 0; i < strlen(input); i++)
    {
        if (!isalpha(input[i]))
        {
            return false;
        }
    }
    return true;
}