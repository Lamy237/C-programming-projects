/*
inputs.h
---------

By Lamy237

Role: Prototypes of functions used to safely read inputs

Creation: July, 7 2022.
*/

#ifndef INPUTS_H_INCLUDED
#define INPUTS_H_INCLUDED

    void free_buffer();

    char read_char();
    int read_string(char *word, int length);

    long read_long();
    double read_double();

#endif // INPUTS_H_INCLUDED
