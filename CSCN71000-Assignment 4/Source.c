#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int MagicNum;
	int result;
	int guessresult = -1;
	int GuessNum;

	printf("Player1, enter the guessing magic number from 1 - 1000 for Player2 (Make sure they are not cheating :D)\n");
	
	do 
	{
		result = scanf("%d", &MagicNum);
		result = validateInput(MagicNum, result);
	} while (result != 1);
	
	system("cls");
	printf("Now pass the game to Player2 to guess the MagicNum (You only got 6 tries) Good Luck!\n Enter a value from 1 - 1000\n");

	if (guessresult == -1)
	{
		for (int incorrectguess = 1; incorrectguess <= 6; incorrectguess++)
		{
			result = scanf("%d", &GuessNum);
			result = validateInput(GuessNum, result);
			if (result == 0)
			{
				printf("X\n");					//Prints X if the guess number entered is an invalid incorrect
			}
			else
			{
				guessresult = guessCheck(MagicNum, GuessNum);
			}
		}
	}
	else
	{
		return 0;
	}
}

int validateInput(input, result)			//Validates the number the users' enter
{
	 if (!(result == 1 && (isdigit(input)) || getchar(input) == '\n'))
	{
		printf("Invalid entry value should be a number, try again.\n");
		return 0;
	}
	else if (input < 1 || input > 1000)
	{
		printf("Invalid entry value should be from 1 - 1000, try again.\n");
		return 0;
	}
	else
	{
		return 1;
	}
}

int guessCheck(int magicnumber, int guessnumber)		//Checks if the magic number has been guessed
{
	if (guessnumber < magicnumber)
	{
		printf("Too Low!\n");
		return -1;
	}
	else if (guessnumber > magicnumber)
	{
		printf("Too High!\n");
		return -1;
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