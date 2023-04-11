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

	//If program is opening with a string as an argument it will be written to file.
	//TODO: This is obviously sloppy and the element number needs to not be hardcoded to accept other arguments in any order.
	if (argv[1] != NULL) {
		write_to_file(argv[1]);
		return 0;
	}

	printf("Welcome to litejournal 0.01!\n\n");
	printf("Default journal loaded...\n\n");

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