/*
main.c
--------

By Lamy237, for the Number guessing game (OpenClassrooms)

Creation: June 05, 2022 at 4:39 PM (Indian Time)

*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int main(int argc, char *argv[])
{

    const int MIN = 1;
    int continueGame = 0, gameMode = 0, level = 0, max = 0;

    printf("\n===WELCOME TO THE NUMBER GUESSING GAME !!!===\n");

    // Prompt the user for the game mode
    do
    {
        printf("1. MODE 1 (1 Player)\n");
        printf("2. MODE 2 (2 Players)\n\n");
        printf("Enter your choice : ");
        scanf("%d", &gameMode);

        if(gameMode != 1 && gameMode != 2)
            printf("\nChoice not registered, please enter a valid option.\n");
    }while(gameMode != 1 && gameMode != 2);


    // Prompt the user for the level of difficulty
    do
    {
        printf("\nSelect a level\n");
        printf("1. Level 1 (1 - 100)\n");
        printf("2. Level 2 (1 - 1000)\n");
        printf("3. Level 3 (1 - 10000)\n\n");
        printf("Enter your choice : ");
        scanf("%d", &level);

        if(level < 1 || level > 3)
            printf("\nChoice not registered, please enter a valid option.\n");
    }while(level < 1 || level > 3);

    // Set the value of max
    max = (level == 1) ? 100: (level == 2) ? 1000: 10000;


    do
    {
        int secretNumber = 0, number = 0, count = 0;

        if(gameMode == 1) // MODE 1 : The number is generated randomly between MIN and max
        {
            srand(time(NULL));
            secretNumber = (rand() % (max - MIN + 1)) + MIN;
        }
        else // MODE 2 : The first player enters the secret number
        {
            do
            {
                printf("\nEnter a secret number between %d and %d : ", MIN, max);
                scanf("%d", &secretNumber);

                if(secretNumber < MIN || secretNumber > max)
                    printf("\nThe entered number is out of the required interval, please try again.\n");
            }while(secretNumber < MIN || secretNumber > max);
        }

        // The actual game
        do
        {
            printf("\nWhat is the secret number ? ");
            scanf("%d", &number);
            count++;

            if(number < secretNumber)
                printf("The secret number is greater.\n\n");
            else if(number > secretNumber)
                printf("The secret number is smaller.\n\n");
            else
                printf("Congratulations, you found the secret number after %d chance(s) !!!\n\n", count);
        }while(number != secretNumber);


        do
        {
            printf("Select an option\n");
            printf("1. New Game\n2. Quit\n\n");
            printf("Enter your choice : ");
            scanf("%d", &continueGame);
            printf("\n");

            if(continueGame != 1 && continueGame != 2)
                printf("Choice not registered, please enter a valid option.\n");
        }while(continueGame != 1 && continueGame != 2);

    }while(continueGame == 1);

    return EXIT_SUCCESS;
}
