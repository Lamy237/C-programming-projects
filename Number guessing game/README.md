## Objective
The goal of the game is to guess a secret number generated or set between a well defined interval.

## Structure
The game has two (02) playing modes:
- `Mode 1` : In which the secret number is automatically generated and is played by a single individual.
- `Mode 2` : Played by two (02) individuals, where the first will set the secret number and the second will have to guess which number it is.

Regardless of the chosen game mode, the user will be prompted to select the level of difficulty. The selected level will determine the interval in which the secret
number is to be generated or set. 

The following table shows the available levels and their covered intervals :
|Level      | Covered Interval|
|-----------|:---------------:|
|Level 1    |1 - 100          |
|Level 2    |1 - 1000         |
|Level 3    |1 - 10000        |


After the game mode and the level are set, the user will now have to guess the secret number under the following conditions :
1. **The user enters a wrong number :** A message is displayed on the screen indicating whether the secret number is smaller or greater than the entered number.
2.  **The user enters the correct number :** A congratulatory message is displayed to the user indicating the number of attempts needed to find the secret number.

Once the secret number is found, the user is prompted to choose whether to exit the game or play another party. The game is restarted as long as the user chooses 
to play another party.

## Sample Output
![img](https://i.ibb.co/8MfB498/A.png)
