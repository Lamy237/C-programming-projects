## Objective
The goal of the game is to guess a secret word by suggesting letters within a certain number of guesses.


## Prerequisites
- Arrays
- Pointers
- Dynamic memory allocation
- Strings and files manipulation
- Conditionnal statements and iterations


## Structure
The game is made up of two (02) playing modes :
- `Mode 1` : The secret word is randomly selected from a dictionary of words. In this case, the game is played by a single individual.
- `Mode 2` : Played by two (02) individuals, in which one player sets the secret word and the second will have to guess it.

The player is given 10 chances to guess the secret word by suggesting letters under the following conditions :

**Note** : Suppose the secret word is `ELEMENT`
1. **The entered letter is in the word** : The secret word is displayed, revealing the found letters. For example, if the letter **E** is entered, we get `E*E*E**`.
2. **The entered letter is not in the word** : The number of chances left is decreased by one. If the number of chances reaches zero (0), the player loses the game.

The drawing of a man getting hanged is displayed as the player enters the wrong letter.


## Dictionary of words
The dictionary of words is a file that contains several words from which one will be randomly picked in case the player chooses `Mode 1`. 

To add a word to the dictionary, the following rules must be respected :
- The file should contain a single word on each line. 
- All the words in the dictionary must be capitalized (written in capital letters).
- There must be one (1) empty line at the end of the file.

```
MORNING
XYLOPHONE
CHAMPIONSHIP

```

