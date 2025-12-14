#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int secretNumber, guess;
    int chances, difficulty;
    char playAgain;

    // Seed random number generator
    srand(time(0));

    do {
        printf("\n🎯 Welcome to the Number Guessing Game!\n");
        printf("Select Difficulty Level:\n");
        printf("1. Easy   (5 chances)\n");
        printf("2. Medium (3 chances)\n");
        printf("3. Hard   (1 chance)\n");
        printf("Enter your choice (1-3): ");
        scanf("%d", &difficulty);

        // Set chances based on difficulty
        if (difficulty == 1)
            chances = 5;
        else if (difficulty == 2)
            chances = 3;
        else if (difficulty == 3)
            chances = 1;
        else {
            printf("❌ Invalid choice. Defaulting to Medium.\n");
            chances = 3;
        }
        // Generate random number between 1 and 100
        secretNumber = (rand() % 100) + 1;

        printf("\nI have selected a number between 1 and 100.\n");
        printf("You have %d chances to guess it.\n", chances);

        int won = 0;

        for (int i = 1; i <= chances; i++) {
            printf("\nChance %d - Enter your guess: ", i);
            scanf("%d", &guess);

            if (guess == secretNumber) {
                printf(" Congratulations! You guessed the correct number.\n");
                won = 1;
                break;
            } 
            else if (guess < secretNumber) {
                printf(" Too low! Try a higher number.\n");
            } 
            else {
                printf(" Too high! Try a lower number.\n");
            }
        }

        if (!won) {
            printf("\n You lost! The correct number was %d.\n", secretNumber);
        }

        printf("\nDo you want to play again? (y/n): ");
        scanf(" %c", &playAgain);

    } while (playAgain == 'y' || playAgain == 'Y');

    printf("\nThanks for playing! 👋\n");
    return 0;
}