/*
dico.c
------

By Lamy237, for the HANGMAN game (OpenClassrooms)

Role: Definition of functions used to randomly choose a word from the dictionary

Last Update: June 12, 2022
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#include "dico.h"


int choose_word(char chosenWord[])
{
    FILE *dict = NULL;

    int numberOfWords = 0, chosenWordNumber = 0;
    char currentChar = 0;

    dict = fopen("dico.txt", "r");

    if(dict == NULL)
    {
        puts("Unable to open the file.");
        return 0;
    }

    // Counting the number of words in the dictionary
    do
    {
        currentChar = fgetc(dict);

        if(currentChar == '\n')
            numberOfWords++;

    }while(currentChar != EOF);

    // Randomly picking a word in the dictionary
    chosenWordNumber = random(numberOfWords);

    // Bringing the cursor back at the beginning of the file
    rewind(dict);

    // Placing the cursor in front of the chosen word to read it
    while(chosenWordNumber > 0)
    {
        currentChar = fgetc(dict);

        if(currentChar == '\n')
            chosenWordNumber--;
    }

    // Reading the chosen word into a string array
    fgets(chosenWord, MAX, dict);

    /* Replacing the '\n' by an '\0' to mark the end of the word. Otherwise, the
    program will read the '\n' as a character, hence giving us a false length of the word */
    chosenWord[strlen(chosenWord) - 1] = '\0';

    fclose(dict); // Do not forget to close the file

    return 1;
}


int random(int maximum)
{
    int number = 0;

    srand(time(NULL));
    number = rand() % maximum;

    return number;
}

