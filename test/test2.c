#include <stdio.h>
#include <cs50.h>

int len(int a);
int cc_len(long long int ccl);
int main(void)
{
    // int sum;
    int count;
    //int p;
    long long int l;

    //p = get_int("P: ");
    l = get_long_long("L: ");
    //printf("You entered: %i\n",p);
    printf("You entered: %lld\n",l);
    //if ((p % 2) != 0)
    //{
        //printf("Odd Number\n");
    //}
    //else
    //{
        //printf("Even Number\n");
    //}
    count = cc_len(l);
    //sum = len(p);
    //printf("Returned Value: %i\n", sum);
    printf("Counter: %i\n", count);

}
int cc_len(long long int ccl)
{
    int a = 0;
    while (ccl > 100)
    {
        printf("Before: %lld\n", ccl);
        ccl = ccl / 10;
         a++;
        printf("After: %lld\n", ccl);
    }
    return a; //return ccl, instead to get the last 2, or 1 numbers for checking against start numbers of amex, master and visa.
}
int len(int a)
{
    int b = 0;
    while (a > 0)
    {
        b = b + (a % 10);
        a = a / 10;
    }
    return b;
}