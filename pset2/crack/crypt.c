#define _XOPEN_SOURCE
#include <stdio.h>
#include <string.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
    char *pass = argv[1];
    char *salt = argv[2];
    if (argc != 3)
    {
        printf("No password or salt recieved.\n");
        return 1;
    }
    if (strlen(pass) < 1)
    {
        printf("Password must be atleast 1 character.\n");
        return 1;
    }
    if (strlen(pass) > 5)
    {
        printf("Password maybe no longer than 5 characters.\n");
        return 1;
    }
    if (strlen(salt) > 2)
    {
        printf("Salt must be only 2 characters.\n");
        return 1;
    }
    if (strlen(salt) < 2)
    {
        printf("Salt must be only 2 characters.\n");
        return 1;
    }

    printf("Hashed Password:\n");
    printf("%s\n", crypt(pass, salt));

    return 0;
}