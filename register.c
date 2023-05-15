#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_SIZE 100

/**
 * struct Person - a struct to represent a person
 * @name: the person's name
 * @surname: the person's surname
 * @cohort: the person's cohort
 * @location: the person's location
 */
typedef struct Person {
	char name[MAX_SIZE]; // string to hold the person's name
	char surname[MAX_SIZE]; // string to hold the person's surname
	char cohort[MAX_SIZE]; // string to hold the person's cohort
	char location[MAX_SIZE]; // string to hold the person's location
} Person;

/**
 * main - the main function of the program
 * Return: 0 on success
 */
int main(void)
{
	Person begister[MAX_SIZE]; // an array to hold up to MAX_SIZE number of people
	int num_people = 0; // initialize the number of people in the register to 0

	char input[MAX_SIZE];// string to hold the user's input
	int quit = 0; // flag to indicate when the program should quit

	while (!quit) { // continue looping until the user chooses to quit
		printf("\nOptions:\n");
		printf("1. Add person to register\n");
		printf("2. Print register\n");
		printf("3. Quit\n\n");

		printf("Enter option number: ");
		scanf("%s", input); // read the user's input from the console

		switch (atoi(input)) { // convert the input to an integer and use it to determine which option the user selected
			case 1:
				if (num_people >= MAX_SIZE) { // check if the register is full
					printf("Error: register is full!\n"); // display an error message if the register is full
					break; // go back to the main menu
				}

				printf("\nEnter name: ");
				scanf("%s", begister[num_people].name); // read the person's name from the console and store it in the register

				printf("Enter surname: ");
				scanf("%s", begister[num_people].surname); // read the person's surname from the console and store it in the register

				printf("Enter cohort (0-99): ");
				scanf("%s", input); // read the cohort input from the console

				// check if the input is a number and is within the range 0-99
				if (strlen(input) != 2 || !isdigit(input[0]) || !isdigit(input[1]) || atoi(input) < 0 || atoi(input) > 99) {
					printf("Error: cohort must be a two-digit number between 0 and 99!\n"); // display an error message if the input is not valid
					break; // go back to the main menu
				}

				strcpy(begister[num_people].cohort, input); // store the cohort in the register

				printf("Enter location: ");
				scanf("%s", begister[num_people].location); // read the person's location from the console and store it in the register

				num_people++;
				break;
			case 2:
				printf("\nregister:\n");
				for (int i = 0; i < num_people; i++) { // loop through the register and print out each person's information
					printf("%s %s, Cohort %s, Location: %s\n", 
						begister[i].name,
						begister[i].surname,
						begister[i].cohort,
						begister[i].location);
				}
				break;
			case 3:
				printf("\nGoodbye!\n");
				quit = 1; // set the quit flag to indicate that the program should quit
				break;
			default:
				printf("\nError: invalid option number!\n"); // display an error message if the user entered an invalid option number
				break;
		}
	}


	return 0;
}
