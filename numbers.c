/*
CS 2600
In-class 1
Part 2: Number guessing game
Matthew Alcasabas

1. Print out main menu
	a. Press 1 to play a game
	b. Press 2 to change the max number
	c. Press 3 to quit

2. If option 1 is selected:
	a. Generate a random number between 1 and maxNumber (by default, 10)
	b. User enters a number
	c. If number too low, tell user, and have them guess again
	d. If number too high, see c
	e. If number is correct, go back to main menu

3. If option 2 is selected:
	a. Change maxNumber from 10 to whatever user inputs
	b. See 2b

4. If option 3 is selected:
	a. Print "Thanks for playing!"
	b. Exit
*/

#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <stdbool.h>

static bool playAgain = false;

int randInt(int a, int b) {
	int r;
	r = a + rand() % (b-a+1);
	return r;
}

void startGame(int max);

int main() {
      unsigned int choice;
      unsigned int maxNumber = 10, userInput;
      restartGame: ;
           time_t t;
           srand((unsigned) time(&t));

      printf("Press 1 to start game\nPress 2 to change max number\nPress 3 to quit\n");
      scanf("%d", &choice);
      switch(choice) {
         case 1:
            playAgain = false;
            while(!playAgain) {
               startGame(maxNumber);
            }
            goto restartGame;
         case 2:
            printf("Please enter a max number (between 1 and RAND_MAX)\n");
            bool validInput = false;
            while(!validInput) {
               scanf("%d", &userInput);
               if(userInput < 1) {
                  printf("Max number should be greater than 1.\n");
               }
               else if (userInput > RAND_MAX) {
                  printf("Max number is too high.\n");
               }
               else {
                  printf("New max number set to %d.\n", userInput);
                  validInput = true;
               }
            maxNumber = userInput;
            while(!playAgain) {
               startGame(maxNumber);
            }
            goto restartGame;
         case 3:
            printf("Thanks for playing!\n");
            return 0;
         default:
            printf("Invalid choice. Please choose 1, 2, or 3.\n");
            goto restartGame;
      }
      return 0;
}
}

void startGame(int max) {
	int randNumber = randInt(1, max);
	bool playerWon = false;
	while(!playerWon) {
      int userInput;
		printf("Pick a number between 1 and %d, or enter q to exit to main menu.\n", max);
      scanf("%d", &userInput);
      char checkForExit = getchar();
		if(userInput == randNumber) {
			printf("You win!\n");
			playerWon = true;
         playAgain = true;
		}
      else if(checkForExit == 'q') {
         printf("Returning to main menu.\n");
         main();
      }
		else if(userInput < randNumber) {
			printf("Too low, please try again!\n");
		}
		else if(userInput > randNumber) {
			printf("Too high, please try again!\n");
		}
      else {
			printf("Unknown input, please try again!\n");
         break;
		}
	}
}
