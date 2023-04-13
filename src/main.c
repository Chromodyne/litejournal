/*
	litejournal Version 0.01a

	Created by: Devin Sinitiere

	This software is licensed under the GNU Public License. 

	This software is provided AS IS with no warranty.
*/
#include<stdio.h>
#include<stdbool.h>
#include<ctype.h>
#include<argp.h>
#include "../include/journal.h"

static int parse_opt(int key, char *arg, struct argp_state *state) {
	
	switch (key) {

		//New entry.
		case 'n': {

			printf("Should write a new entry.\n");
			break;

		}

	}

	return 0;

}

int main(int argc, char **argv) {

	struct argp_option options[] = {
		{0, 'n', 0, 0, "Create a new entry"},
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