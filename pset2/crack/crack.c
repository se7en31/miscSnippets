/*
get salt = first two char of hashed password
for loop through every possible 4 letter combo with null
terminator. Every combo of 1 letter password, (lower and upper)
every combo of 2 letter, etc. if hash of crypt(salt, key) =
hashed password passed into program halt.

anushree:50xcIMJ0y.RXo
brian:50mjprEcqC/ts
bjbrown:50GApilQSG3E2
lloyd:50n0AAUD.pL8g
malan:50CcfIk1QrPr6
maria:509nVI8B9VfuA
natmelo:50JIIyhDORqMU
rob:50JGnXUgaafgc
stelios:51u8F0dkeDSbY
zamyla:50cI2vYkF0YU2

Hints
Be sure to read up on crypt, taking particular note of its mention of "salt":
man crypt
Per that man page, you’ll likely want to put
#define _XOPEN_SOURCE
#include <unistd.h>
at the top of your file in order to use crypt.

Specification

Design and implement a program, crack, that cracks passwords.
Implement your program in a file called crack.c in a directory called crack.
Your program should accept a single command-line argument: a hashed password.
If your program is executed without any command-line arguments or with more than one command-line argument, your program should print an error (of your choice) and exit immediately, with main returning 1 (thereby signifying an error).
Otherwise, your program must proceed to crack the given password, ideally as quickly as possible, ultimately printing the password in the clear followed by \n, nothing more, nothing less, with main returning 0.
Assume that each password has been hashed with C’s DES-based (not MD5-based) crypt function.
Assume that each password is no longer than five (5) characters. Gasp!
Assume that each password is composed entirely of alphabetical characters (uppercase and/or lowercase).
*/
#define _XOPEN_SOURCE
#include <stdio.h>
#include <string.h>
#include <unistd.h>


int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("No hashed password provided.\n");
        return 1;
    }

    char table[53] = {'A', 'a', 'B', 'b', 'C', 'c', 'D', 'd', 'E', 'e', 'F', 'f', 'G', 'g', 'H', 'h', 'I', 'i', 'J', 'j', 'K', 'k', 'L', 'l', 'M', 'm', 'N', 'n', 'O', 'o', 'P', 'p', 'Q', 'q', 'R', 'r', 'S', 's', 'T', 't', 'U', 'u', 'V', 'v', 'W', 'w', 'X', 'x', 'Y', 'y', 'Z', 'z', '\0'};
    char *ec = argv[1];
    char salt[3] = {ec[0], ec[1], '\0'};
    char current[6];
    int attempt = 0;

    if (strlen(ec) != 13)
    {
        printf("Invalid hashed password length.\n");
        return 1;
    }
    printf("Password Length 1\n");
    for (int i = 0; i < strlen(table); i++) //initial loop through single char, lather rinse repeat 4 more times
    {
        current[0] = table[i];
        current[1] = '\0';
        //printf("current: %s  Hash: %s\n", current, crypt(current,salt));
        attempt++;
        if ((strcmp(crypt(current, salt), ec) == 0))
        {
            //printf("Matched Password: %s\n", current);
            printf("%i attempts before sucessfully cracking password: %s", attempt, current);
            return 0;
        }
    }
    printf("Password Length 2\n");
    for (int i = 0; i < strlen(table); i++) //loop 2 for 2 char pass
    {
        for (int j = 0; j < strlen(table); j++)
        {
            current[0] = table[i];
            current[1] = table[j];
            current[2] = '\0';
            //printf("current: %s  Hash: %s\n", current, crypt(current,salt));
            attempt++;
            if ((strcmp(crypt(current, salt), ec) == 0))
            {
                //printf("Matched Password: %s\n", current);
                printf("%i attempts before sucessfully cracking password: %s", attempt, current);
                return 0;
            }
        }
    }
    printf("Password Length 3\n");
    for (int i = 0; i < strlen(table); i++) //loop 3 for 3 char pass
    {
        for (int j = 0; j < strlen(table); j++)
        {
            for (int k = 0; k < strlen(table); k++)
            {
                current[0] = table[i];
                current[1] = table[j];
                current[2] = table[k];
                current[3] = '\0';
                //printf("current: %s  Hash: %s\n", current, crypt(current,salt));
                attempt++;
                if ((strcmp(crypt(current, salt), ec) == 0))
                {
                    //printf("Matched Password: %s\n", current);
                    printf("%i attempts before sucessfully cracking password: %s", attempt, current);
                    return 0;
                }
            }
        }
    }
    printf("Password Length 4\n");
    for (int i = 0; i < strlen(table); i++) //loop 4 for 4 char pass
    {
        for (int j = 0; j < strlen(table); j++)
        {
            for (int k = 0; k < strlen(table); k++)
            {
                for (int l = 0; l < strlen(table); l++)
                {
                    current[0] = table[i];
                    current[1] = table[j];
                    current[2] = table[k];
                    current[3] = table[l];
                    current[4] = '\0';
                    //printf("current: %s  Hash: %s\n", current, crypt(current,salt));
                    attempt++;
                    if ((strcmp(crypt(current, salt), ec) == 0))
                    {
                        //printf("Matched Password: %s\n", current);
                        printf("%i attempts before sucessfully cracking password: %s", attempt, current);
                        return 0;
                    }
                }
            }
        }
    }
    printf("Password Length 5\n");
    for (int i = 0; i < strlen(table); i++) //loop 5 for 5 char pass
    {
        for (int j = 0; j < strlen(table); j++)
        {
            for (int k = 0; k < strlen(table); k++)
            {
                for (int l = 0; l < strlen(table); l++)
                {
                    for (int m = 0; m < strlen(table); m++)
                    {
                        current[0] = table[i];
                        current[1] = table[j];
                        current[2] = table[k];
                        current[3] = table[l];
                        current[4] = table[m];
                        current[5] = '\0';
                        //printf("current: %s  Hash: %s\n", current, crypt(current,salt));
                        attempt++;
                        if ((strcmp(crypt(current, salt), ec) == 0))
                        {
                            //printf("Matched Password: %s\n", current);
                            printf("%i attempts before sucessfully cracking password: %s", attempt, current);
                            return 0;
                        }
                    }
                }
            }
        }
    }
    printf("No match found\n");
    return 0;
}