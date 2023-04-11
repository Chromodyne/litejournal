/*
	litejournal Version 0.01a

	Created by: Devin Sinitiere

	This software is licensed under the GNU Public License. 

	This software is provided AS IS with no warranty.
*/
#include<stdio.h>
#include<stdbool.h>
#include<ctype.h>
#include "../include/journal.h"

int main(int argc, char **argv) {

	//Controls the main loop of the program.
	bool shouldQuit = false;

	printf("Welcome to litejournal 0.01!\n\n");
	printf("Default journal loaded...\n\n");

	//TODO: Check if a new journal file should be created. If so, create one and load it. Otherwise choose a journal file to load.

	while (!shouldQuit) {

		char selection;

		printf("Please select an option: \n");

		printf("(n) New Entry, (r) Remove Entry, (l) Show latest entry, (o) Open Journal File, (s) Statistics, (q) Quit\n");

		//I don't like having to suppress newline characters this way.
		scanf("%c%*c", &selection);
		selection = tolower(selection);

		switch (selection) {

			case 'n':
				new_entry();
				break;

			case 'r':
				break;

			case 'l':
				list_latest();
				break;
			
			case 'o':
				open_journal();
				break;

			case 'q':
				shouldQuit = true;
				break;

			default:
				printf("\nIncorrect selection specified. ");
				break;

		}

	}

	return 0;

}