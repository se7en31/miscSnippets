// Helper functions for music

#include <cs50.h>

#include "helpers.h"

// Converts a fraction formatted as X/Y to eighths
int duration(string fraction)
{
    // TODO try switch case statement first...
    switch(fraction)
    {
        case "1/8":
            return 1;
            break;
        case "1/4":
            return 2;
            break;
        case "3/8";
            return 3;
            break;
        case "1/2":
            return 4;
            break;
        case "5/8":
            return 5;
            break;
        case "3/4":
            return 6;
            break;
        case "7/8":
            return 7;
            break;
        case "8/8":
            return 8;
            break;
        case default:
            printf("Incorrect Syntax");
    }
}

// Calculates frequency (in Hz) of a note
int frequency(string note)
{
    // TODO
}

// Determines whether a string represents a rest
bool is_rest(string s)
{
    //possibly use s[0], or s[1], and check for a new line, or null term if strlen ver doesnt work..
    if strlen(s) != 0
        return false;
    else
        return true;
}
