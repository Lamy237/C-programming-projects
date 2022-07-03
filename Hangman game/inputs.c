/*
inputs.c
---------

By Lamy237

Role: Definition of functions used to safely read inputs

Creation: July, 7 2022.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void free_buffer()
{
    int c = 0;

    while(c != '\n' && c != EOF)
    {
        c = getchar();
    }
}


char read_char()
{
    char letter = 0;

    letter = getchar();
    free_buffer();

    return letter;
}


int read_string(char *word, int length)
{
    char *position = NULL;

    if(fgets(word, length, stdin) != NULL)
    {
        position = strchr(word, '\n');

        if(position != NULL)
        {
            *position = '\0';
        }
        else
        {
            free_buffer();
        }

        return 1;
    }
    else
    {
        free_buffer();
        return 0;
    }
}


long read_long()
{
    char numberText[100] = {0};

    if(read_string(numberText, 100))
    {
        return strtol(numberText, NULL, 10);
    }
    else
    {
        return 0;
    }
}


double read_double()
{
    char numberText[100] = {0};

    if(read_string(numberText, 100))
    {
        return strtod(numberText, NULL);
    }
    else
    {
        return 0;
    }
}

