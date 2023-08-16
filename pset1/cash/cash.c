#include <cs50.h>
#include <math.h>
#include <stdio.h>

int main(void)
{
    float n; //user specified float
    int total; //float converted to int
    int counter; //counter for coins required.
    counter = 0;

    do
    {
        n = get_float("Change owed: ");
    }
    while (n < 0);
    total = round(n * 100);

    while (total >= 25)
    {
        total = total - 25;
        counter++;
    }
    while (total >= 10)
    {
        total = total - 10;
        counter++;
    }
    while (total >= 5)
    {
        total = total - 5;
        counter++;
    }
    while (total >= 1)
    {
        total = total - 1;
        counter++;
    }

    printf("%i\n", counter);
}