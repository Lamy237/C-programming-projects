/*
functions.h
-----------

By Lamy237, for the HANGMAN game (OpenClassrooms)

Role: *Prototypes of the functions managing the game

Creation: June 30, 2021 at 15:29 (Indian Time)

Last Update: June 12, 2022
*/

#ifndef FUNCTIONS_H_INCLUDED
#define FUNCTIONS_H_INCLUDED

    char read_char();
    int search_in_word(const char letter, const char word[], int table[]);
    void display_word(const char word[], const int table[]);
    int win(const int table[], int size);
    int read_string(char myString[]);
    void hang(int counter);
    void free_buffer();
    int read_long();

#endif // FUNCTIONS_H_INCLUDED

