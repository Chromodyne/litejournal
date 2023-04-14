/*
	litejournal Version 0.01a

	Created by: Devin Sinitiere

	This software is licensed under the GNU Public License. 

	This software is provided AS IS with no warranty.
*/
#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
#include<ctype.h>
#include "../include/journal.h"
#include "../include/userargs.h"

int main(int argc, char **argv) {

	//Parse command line arguments and options using argp
	parse_arguments(argc, argv);

	bool shouldQuit = false;

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