/*
dico.h
------

By Lamy237, for the HANGMAN game (OpenClassrooms)

Role: *Prototypes of the functions used to randomly choose a word from the dictionary (MODE 1)
      *Definition of the constants used in the program (Preprocessor)

Last Update: June 12, 2022
*/

#ifndef DICO_H_INCLUDED
#define DICO_H_INCLUDED

    #define MAX 100

    int choose_word(char chosenWord[]);
    int random(int maximum);

#endif // DICO_H_INCLUDED
