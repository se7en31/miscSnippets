#include <stdio.h>
#include <math.h>
#include <cs50.h>
#include <stdbool.h>

//4/17/18 Copied all code over from ~/workspace/test/test.c File.
//Feel free to check Rev history of it.

int cc_len(long long int ccl);
bool cc_validate(long long int ccl, int counter);
int cc_pre(long long int ccl, int sel);
int dblsum(int a);

int main(void)
{
    long long int long_n;
    int counter;
    long_n = get_long_long("Number: ");
    if (0 < long_n)
    {
        counter = cc_len(long_n);
        if (counter == 13) // Visa (13) Check
        {
            if (cc_validate(long_n, counter) && cc_pre(long_n, 1) == 4) //Check for starting 4
            {
                printf("VISA\n");
            }
            else
            {
                printf("INVALID\n");
            }
        }
        else if (counter == 15) //check for mastercard()
        {
            if (cc_validate(long_n, counter))
            {
                if (cc_pre(long_n, 2) == 37 || cc_pre(long_n, 2) == 34)
                {
                    printf("AMEX\n");
                }
                else
                {
                    printf("INVALID\n");
                }
            }
            else
            {
                printf("INVALID\n");
            }
        }
        else if (counter == 16) //check for VISA AND MASTERCARD start with 4(visa), or 51-55(MC)
        {
            if (cc_validate(long_n, counter))
            {
                if (cc_pre(long_n, 2) >= 51 && cc_pre(long_n, 2) <= 55)
                {
                    printf("MASTERCARD\n");
                }
                else if (cc_pre(long_n, 1) == 4)
                {
                    printf("VISA\n");
                }
                else
                {
                    printf("INVALID\n");
                }
            }
            else
            {
                printf("INVALID\n");
            }
        }
        else
        {
            printf("INVALID\n");
        }
        return 0;
    }
    else
    {
        return 1;
    }
}

int cc_pre(long long int ccl, int sel)//function to grab first 2, or first digit in CC NUMBER
{
    if (sel > 1)
    {
        while (ccl > 100)
        {
            ccl = ccl / 10;
        }
    }
    else
    {
        while (ccl > 10)
        {
            ccl = ccl / 10;
        }
    }
    return ccl; //return ccl
}

//Gets credit card length.
int cc_len(long long int ccl)
{
    int a = 0;
    while (ccl > 0)
    {
        ccl = ccl / 10;
        a++;
    }
    return a;
}
//checksum validation
bool cc_validate(long long int ccl, int counter)
{
    int ar_size = counter / 2;
    int j = 0; // pos for non multi array
    int k = 1; // pos for overall progress of loop in cc length, also what to check against % 2
    int l = 0; // pos for multi array.
    int totalsum = 0;
    int totalmulti = 0;
    int totalvalid;
    int multi[ar_size]; //array for digits to be multipled.
    int sum[(counter - ar_size)];

    for (int i = 0; i < counter; i++)
    {
        if ((k % 2) != 0) // k counter does not equal 0 from % 2 then put into array for sum total
        {
            sum[j] = ccl % 10;
            ccl = ccl / 10;
            j++;
            k++;
        }
        else //if k counter = 0 then put into multi array.
        {
            multi[l] = ccl % 10 * 2;
            ccl = ccl / 10;
            l++;
            k++;
        }
    }

    for (int m = 0; m < sizeof(sum) / sizeof(sum[0]); m++)
    {
        totalsum = totalsum + sum[m];
    }

    for (int n = 0; n < sizeof(multi) / sizeof(multi[0]); n++)
    {
        if (cc_len(multi[n]) > 1)
        {
            totalmulti = totalmulti + dblsum(multi[n]);
        }
        else
        {
            totalmulti = totalmulti + multi[n];
        }
    }

    totalvalid = totalsum + totalmulti;

    if ((totalvalid) % 10 != 0)
    {
        return false;
    }
    else
    {
        return true;
    }
}

int dblsum(int a) //takes double digit returns for the *2 multiplication, adds each digit and returns
{
    int b = 0;
    while (a > 0)
    {
        b = b + (a % 10);
        a = a / 10;
    }
    return b;
}