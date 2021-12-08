#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int ValidateInput(int input);
int GuessCheck(int magicnumber, int guessnumber);
int input(void);

int main(void)
{
	return 0;
}

int input(void)
{
	int user_input = 0;

	printf("Player1, enter the guessing magic number from 1 - 1000 for Player2 (Make sure they are not cheating :D)\n");

	int result = scanf("%d\n", &user_input);

	if (result == 1 && getchar() == '\n')
	{
		return user_input;
	}
	else
	{
		return 0; // False / Invalid
	}
	ValidateInput(input);

}

int ValidateInput(int input)
{
	if (input < 1 || input > 1000)
	{
		printf("Invalid entry value should be a number from 1 - 1000, try again.");
		return 0; // Invalid
	}
	else if (!(isdigit(input)))
	{
		printf("Invalid entry value should be a number, try again.\n");
		return 0;
	}
	else
	{
		return 1;
	}
}

int GuessCheck(int magicnumber, int guessnumber)
{
	for (int IncorrectGuess = 0; IncorrectGuess < 6;)
	{
		int result1 = scanf("%d", &guessnumber);

		if (guessnumber < magicnumber)
		{
			printf("Too Low!\n");
			IncorrectGuess++;
		}
		else if (guessnumber > magicnumber)
		{
			printf("Too High!\n");
			IncorrectGuess++;
		}
		else if (guessnumber == magicnumber)
		{
			printf("You won!");
			return 1;
		}
		else
		{
			printf("You lost!");
			return 0;
		}
	}
}