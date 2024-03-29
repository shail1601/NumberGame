/*
*
* Name: Shail Thakkar
* Assignment: Guessing game
* Date: July 4th, 2019
* Description: A number guessing game that randomly picks a number from 1-100.
  The user has 100 tries to get the correct answer. The application tracks the number
  of tries that the user has taken and prints different messages to the screen depending
  on how many times the user has guessed. Additional features include total time, sounds,
  error handeling, able to set range of values, prints different messages based on amount
  of tries, and indicates if the number you guess is higher or lower than the actual number.
*
*/

#include <stdio.h>
#include <time.h>
#include <stdlib.h>

//void clearValues(void) //Start of the function "clearin"
//{
//while(getchar() != '\n'){};	//Cleans all the junk
//return;
//}

void thumbsUp() {
	//Prints a thumbs up to the screen
	printf("            _\n");
	printf("           /(|\n");
	printf("          (  :\n");
	printf("         __\\  \\  _____\n");
	printf("       (____)  `|\n");
	printf("      (____)|   |\n");
	printf("       (____).__|\n");
	printf("        (___)__.|_____\n");
}

int playGame()	//Function that contains the majority of the code to play the game
{
long randomNumber;	//Variable used to store the random number that is generated
long numberOfTries = 0;	//Variable used to store how many times the user has guess a number
long numberGuessed = 0;	//Variable used to store the number that the user inputs
int startingTime = 0;	//Variable used to store the starting time when the application begins
int guessRange = 0;	//Variable used to store the number range that the user set
int invalid = 0;	//Variable used to check if the user inputs an integer or not
int rangeInvalid = 0; //Variable used to check if the user inputs an integer or not

system("clear");	//Clears the screen
startingTime = time(NULL);	//Gets the starting time
srand(time(NULL));		//Seeds the random number
printf("Pick a guess range number\n");	//Instruction telling user to set the guess range

	while(guessRange == 0)	//Used to set the guess range at the begining of the program
	{
	rangeInvalid = scanf("%i", &guessRange);	//Tracks the number that the user inputs
	//clearValues();	//Clears all "Junk"
		if(rangeInvalid == 1) // Checks if the user inputs an integer
		{
		randomNumber=rand()%guessRange;	//Gets a random number from based on remainder and the guess range set by user
		}
			else
			{
			printf("Invalid range try again\n");
			}
	}
	randomNumber++;			//Increases the random number by 1 so the value becomes 1-100 instead of 0-99
	printf("Guess a number from 1 to %i! \n", guessRange);	//Prints of standard starting message

	while(1)
	{
	invalid = scanf("%i", &numberGuessed);	//Tracks the number that the user inputs
	//clearValues();	//Clears all "Junk"

	if(invalid == 1) // Checks if the user input an integer if not will print an error message
		{
			if(numberGuessed <= guessRange)	//Used to check if the user has guessed a number within the range set
			{
			numberOfTries++;	//Increases the counter that checks how many times the user has guessed if not will print an error message
			}
			else
			{
			printf("Invalid number please guess again, this guess will not count\n\7");	//Error message for when the user inputs a mych larger integer
			}
		}
			else
			{
			printf("Thats not even a number, come on man!\n\7"); //Error message for when the user doesnt input an integer
			}

	if(invalid > 1) // Prints a message if the user inputs more than one value
		{
		printf("Too many numbers for me to handle, one at a time please!\n");
		}

		if(numberOfTries == guessRange)	//Prints a message and closes the application when the number of tries has reached 100
		{
		printf("You have guessed %i times. You have got to be trolling me. There isnt any other possible number to guess now unless you are intentionally trying to get it wrong :( I'm going to shut you off now!!! \n", numberOfTries);
		printf("You wasted %d seconds of my life! -_-\n", time(NULL) - startingTime);	//Displays total time taken
		thumbsUp();	//Calls thumbsUp function
		return 0;
		}

			if(numberGuessed == randomNumber) 	//Happens only when the user has guess the correct number
			{
			printf("Congrats you guessed the number correctly!\n\7");	//Prints off that the user has guessed correctly
			printf("It took you %i tries to guess it correctly!\n\7", numberOfTries);	//Prints off how many tries it took for the user to guess correctly
				if(numberOfTries <= guessRange*0.1) //If the user took under 10% of the guess range in tries to get the correct number, prints off a message
				{
				printf("You are above average at guessing!\n");
				}
					else if (numberOfTries > guessRange*0.8)	//Prints a message if the user took over 80%  of the guess range number in tries
					{
					printf("You have bad luck at guessing!\n");
					}
						else	//Prints a message if the user took over 10% but under 80% of the guess range number in tries
						{
						printf("You are average at guessing!\n");
						}
			printf("The total time you took guess the number was %d seconds\n", time(NULL) - startingTime); //Displays total time taken
			thumbsUp();	//Calls thumbsUp function
			return 0;
			}

		if(numberGuessed != randomNumber && numberGuessed <= guessRange && invalid == 1)	//Happens only when the user guesses the incorrect number and the number guessed is within the range
		{
			if(numberGuessed < randomNumber)	//Prints a message telling the user that their guess was too low
			{
			printf("Sorry, your guess was too low\n");
			}
				if(numberGuessed > randomNumber)
				{
				printf("Sorry, your guess was too high\n");	//Prints a message telling the user that their guess was too high
				}

					if(numberOfTries <= guessRange*0.2) 	//Prints a message if the user has guessed less than 20% of the guess range number in tries
					{
					printf("You guessed wrong! Try again!\n");
					}
						if(numberOfTries > guessRange*0.2 && numberOfTries <= guessRange*0.4)	//Prints a message if the user has guessed more than 20% but less than 40% of the guess range number in tries
						{
						printf("Come on you got this!\n");
						}
							if(numberOfTries > guessRange*0.4 && numberOfTries <= guessRange*0.6)	c//Prints a message if the user has guessed more than 40% but less than 60% of the guess range numbers
							{
							printf("Keep trying!\n");
							}
								if(numberOfTries > guessRange*0.6 && numberOfTries <= guessRange*0.8)	//Prints a message if the user has guessed more that 60% but less than 80% of the guess range numbers
								{
								printf("You've got this!\n");
								}
									if(numberOfTries > guessRange*0.8)	//Prints a message if the user has guessed more than 80% of the guess range numbers
									{
									printf("Are you even trying now???\n");

									}
		}
	}
}

int main()
{
playGame();
}
