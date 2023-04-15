#include<argp.h>
#include<string.h>
#include<stdlib.h>
#include "../include/journal.h"

static int parse_opt(int key, char *arg, struct argp_state *state) {
	
	switch (key) {

		case 'l': {
			
			//TODO: Fix this once multiple lines can be read.
            if (arg != NULL) {
                list_latest(atoi(arg));
                exit(EXIT_SUCCESS);
            } else {
                list_latest(1);
                exit(EXIT_SUCCESS);
            }
			
			break;

		}

		case 'n': {

			//Check if the supplied argument exists, if so, use it to create an entry. Otherwise,
			//invoke new_entry and give user a prompt to enter their new entry.
			if (arg != NULL) {
				write_to_file(arg);
				exit(EXIT_SUCCESS);
				
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

		case 'r': {

			remove_journal();
			exit(EXIT_SUCCESS);
			break;

		}

	}

	return 0;

}


void parse_arguments(int argc, char **argv) {

    struct argp_option options[] = {
		{"list-entries", 'l', "NUMENTRIES", OPTION_ARG_OPTIONAL, "List specified number of entries"},
		{"new-entry", 'n', "TEXT", OPTION_ARG_OPTIONAL, "Create a new entry"},			//TODO: Takes a string as an argument.
		{"open-journal", 'o', 0, 0, "Open journal file in default editor"},
		{"remove-journal", 'r', 0, 0, "Delete journal file"},
		{0}
	};

	struct argp argp = { options, parse_opt };

	argp_parse(&argp, argc, argv, 0, 0, 0);
    
}
