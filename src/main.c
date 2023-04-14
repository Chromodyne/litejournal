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
#include<argp.h>
#include "../include/journal.h"

static int parse_opt(int key, char *arg, struct argp_state *state) {
	
	switch (key) {

		case 'l': {
			
			printf("Will list entries of specified number.\n");

			break;

		}


		case 'n': {


			//Check if the supplied argument exists, if so, use it to create an entry. Otherwise,
			//invoke new_entry and give user a prompt to enter their new entry.
			if (arg != NULL) {
				//TODO: Doesn't work. Solve.
				write_to_file(arg);
				
			} else {
				new_entry();
				exit(EXIT_SUCCESS);
			}


			break;

		}

		case 'o': {

			open_journal();
			exit(EXIT_SUCCESS);
			break;

		}

	}

	return 0;

}

int main(int argc, char **argv) {

	struct argp_option options[] = {
		{"list-entries", 'l', "NUMENTRIES", OPTION_ARG_OPTIONAL, "List specified number of entries"},
		{"new-entry", 'n', "TEXT", OPTION_ARG_OPTIONAL, "Create a new entry"},			//TODO: Takes a string as an argument.
		{"open-journal", 'o', 0, 0, "Open journal file in default editor"},
		{0}
	};

	struct argp argp = { options, parse_opt };

	argp_parse(&argp, argc, argv, 0, 0, 0);

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