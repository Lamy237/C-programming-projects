#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "functions.h"
#include "dico.h"


int main(int argc, char *argv[])
{
    char secretWord[MAX] = {0}, letter = 0;
    int *found = NULL, sizeWord = 0;
    long decision = 0, gameMode = 0;

    puts("\n=== WELCOME TO THE HANGMAN GAME !!! ===\n");

    // Prompt the user for the game mode
    do
    {
        puts("1. MODE 1 (1 Player)");
        puts("2. MODE 2 (2 Players)\n");

        fputs("Enter your choice : ", stdout);
        gameMode = read_long();

        if(gameMode != 1 && gameMode != 2)
            puts("\nChoice not registered, please enter a valid option");
    }while(gameMode != 1 && gameMode != 2);


    do
    {
        // The player has 10 tries to find the secret word
        int chances = 10;

        if(gameMode == 1) // MODE 1 : The secret word is selected randomly from the dictionary
        {
            if(!choose_word(secretWord))
                exit(EXIT_FAILURE);
        }
        else // MODE 2 : The first player enters the secret word
        {
            fputs("\nEnter the secret word: ", stdout);
            read_string(secretWord);
            strupr(secretWord);
        }

        //printf("\nThe secret word is %s\n", secretWord);

        sizeWord = strlen(secretWord);

        found = malloc(sizeWord * sizeof(int));
        if(found == NULL)
        {
            puts("Couldn't allocate the memory");
            exit(EXIT_FAILURE);
        }

        // Initialize the values of 'found'
        for(int i=0; i<sizeWord; i++)
        {
            found[i] = 0;
        }

        while(chances > 0 && !win(found, sizeWord))
        {
            printf("\nYou have %d chance(s) left\n", chances);
            fputs("What is the secret word ? ", stdout);

            display_word(secretWord, found);

            fputs("\nEnter a letter: ", stdout);
            letter = read_char();

            if(!search_in_word(letter, secretWord, found))
                chances--;

            hang(chances);
        }

        // Print the win or loss message
        if(win(found, sizeWord))
            printf("\nCongratulations, the secret word was : %s !!!\n", secretWord);
        else
            printf("\nGAME OVER ! The secret word was : %s\n", secretWord);

        // Prompt the user to decide whether to continue or not
        do
        {
            puts("\nDo you want to play again ?");
            puts("1. Yes");
            puts("2. No\n");

            fputs("Enter your choice : ", stdout);
            decision = read_long();

            if(decision != 1 && decision != 2)
                puts("\nChoice not registered, kindly read the instructions and try again");
        }while(decision != 1 && decision != 2);


        free(found); // Remember to free the allocated memory

        if(decision == 1)
        {
            puts("\n--------------------------------------");
            puts("              NEW GAME !              ");
            puts("--------------------------------------");
        }
    }while(decision == 1);


    return EXIT_SUCCESS;
}
