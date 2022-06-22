/*
functions.c
-----------

By Lamy237, for the HANGMAN game (OpenClassrooms)

Role: Definition of the functions managing the game

      - read_char() : Reads only the first character entered and erases all the others (empty the buffer)
      - search_in_word() : Verifies whether or not the entered letter is in the word
      - display_word() : Prints the secret word while masking the letters that haven't been found yet
      - win() : Checks whether all the letters of the word were found or not
      - read_string() : Reads the secret word entered by the user and frees the buffer (MODE 2 only)
      - read_long() : Converts a string into a number (long int)
      - hang() : Draws a man getting hanged more and more each time the player enters a wrong letter

Creation: June 30, 2021 at 15:29 (Indian Time)

Last Update: June 12, 2022
*/

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#include "dico.h" //To use the preprocessor MAX


char read_char()
{
    char myChar = 0;

    myChar = getchar();
    myChar = toupper(myChar); //Puts the entered character in upper case if not already in

    while(getchar() != '\n'); //Read all the remaining characters to free the buffer

    return myChar;
}


int search_in_word(const char letter, const char word[], int table[])
{
    int foundLetter = 0;

    for(int i=0; word[i] != '\0'; i++)
    {
        if(letter == word[i])
        {
            foundLetter = 1;
            table[i] = 1;
        }
    }

    return foundLetter;
}


void display_word(const char word[], const int table[])
{
    for(int i=0; word[i] != '\0'; i++)
    {
        if(table[i] == 1)
            printf("%c", word[i]);
        else
            printf("*");
    }
}


int win(const int table[], int size)
{
    int success = 1;

    for(int i=0; i<size; i++)
    {
        if(table[i] == 0)
            success = 0;
    }

    return success;
}


void free_buffer()
{
    int c = 0;

    while(c != '\n' && c != EOF)
    {
        c = getchar();
    }
}


int read_string(char myString[])
{
    char *position = NULL;

    if(fgets(myString, MAX, stdin) != NULL)
    {
        position = strchr(myString, '\n');

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


int read_long()
{
    char numberText[MAX] = {0};

    if(read_string(numberText))
    {
        return strtol(numberText, NULL, 10);
    }
    else
    {
        return 0;
    }
}


void hang(int counter)
{
    switch(counter)
    {
    case 0:
        puts("");
        puts("     ______");
        puts("    |      |");
        puts("    |     ***");
        puts("    |    *   *");
        puts("    |     ***");
        puts("    |      *");
        puts("    |      *");
        puts("    |    * * *");
        puts("    |   *  *  *");
        puts("    |  *   *   *");
        puts("    |      *");
        puts("    |      *");
        puts("    |    *   *");
        puts("    |   *     *");
        puts("    |  *       *");
        puts("    |");
        puts(" ___|___\n");
        break;
    case 1:
        puts("");
        puts("     ______");
        puts("    |      |");
        puts("    |     ***");
        puts("    |    *   *");
        puts("    |     ***");
        puts("    |      *");
        puts("    |      *");
        puts("    |    * * *");
        puts("    |   *  *  *");
        puts("    |  *   *   *");
        puts("    |      *");
        puts("    |      *");
        puts("    |    *  ");
        puts("    |   *   ");
        puts("    |  *    ");
        puts("    |");
        puts(" ___|___\n");
        break;
    case 2:
        puts("");
        puts("     ______");
        puts("    |      |");
        puts("    |     ***");
        puts("    |    *   *");
        puts("    |     ***");
        puts("    |      *");
        puts("    |      *");
        puts("    |    * * *");
        puts("    |   *  *  *");
        puts("    |  *   *   *");
        puts("    |      *");
        puts("    |      *");
        puts("    |");
        puts("    |");
        puts("    |");
        puts("    |");
        puts(" ___|___\n");
        break;
    case 3:
        puts("");
        puts("     ______");
        puts("    |      |");
        puts("    |     ***");
        puts("    |    *   *");
        puts("    |     ***");
        puts("    |      *");
        puts("    |      *");
        puts("    |    * *");
        puts("    |   *  *");
        puts("    |  *   *");
        puts("    |      *");
        puts("    |      *");
        puts("    |");
        puts("    |");
        puts("    |");
        puts("    |");
        puts(" ___|___\n");
        break;
    case 4:
        puts("");
        puts("     ______");
        puts("    |      |");
        puts("    |     ***");
        puts("    |    *   *");
        puts("    |     ***");
        puts("    |      *");
        puts("    |      *");
        puts("    |      *");
        puts("    |      *");
        puts("    |      *");
        puts("    |      *");
        puts("    |      *");
        puts("    |");
        puts("    |");
        puts("    |");
        puts("    |");
        puts(" ___|___\n");
        break;
    case 5:
        puts("");
        puts("     ______");
        puts("    |      |");
        puts("    |     ***");
        puts("    |    *   *");
        puts("    |     ***");
        puts("    |");
        puts("    |");
        puts("    |");
        puts("    |");
        puts("    |");
        puts("    |");
        puts("    |");
        puts("    |");
        puts("    |");
        puts("    |");
        puts("    |");
        puts(" ___|___\n");
        break;
    case 6:
        puts("");
        puts("     ______");
        puts("    |      |");
        puts("    |");
        puts("    |");
        puts("    |");
        puts("    |");
        puts("    |");
        puts("    |");
        puts("    |");
        puts("    |");
        puts("    |");
        puts("    |");
        puts("    |");
        puts("    |");
        puts("    |");
        puts("    |");
        puts(" ___|___\n");
        break;
    case 7:
        puts("");
        puts("     ______");
        puts("    |");
        puts("    |");
        puts("    |");
        puts("    |");
        puts("    |");
        puts("    |");
        puts("    |");
        puts("    |");
        puts("    |");
        puts("    |");
        puts("    |");
        puts("    |");
        puts("    |");
        puts("    |");
        puts("    |");
        puts(" ___|___\n");
        break;
    case 8:
        puts("");
        puts("    |");
        puts("    |");
        puts("    |");
        puts("    |");
        puts("    |");
        puts("    |");
        puts("    |");
        puts("    |");
        puts("    |");
        puts("    |");
        puts("    |");
        puts("    |");
        puts("    |");
        puts("    |");
        puts("    |");
        puts(" ___|___\n");
        break;
    case 9:
        puts("\n______\n");
        break;
    }
}

