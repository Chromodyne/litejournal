/*
	litejournal Version 0.01a

	Created by: Devin Sinitiere

	This software is licensed under the GNU Public License. 

	This software is provided AS IS with no warranty.
*/

#include<stdio.h>
#include<stdbool.h>
#include<stdint.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#include<unistd.h>

//TODO: Dynamically allocate this if necessary.
#define SUBJECT_LENGTH 100
#define JOURNAL_FILE "journal.lj"

//This struct is used to temporarily store new entries before they are written to the journal file.
typedef struct {

	char subject[SUBJECT_LENGTH];

	//TODO: The length of the body needs to be dynamically allocated at runtime.
	char body[255];
	time_t timestamp;

} Entry;

//Function Prototypes
void new_entry();
void list_entries();
void open_journal();

int main(int argc, char **argv) {

	//Controls the main loop of the program.
	bool shouldQuit = false;

	printf("Welcome to litejournal 0.01!\n\n");
	printf("Default journal loaded...\n\n");

	//TODO: Check if a new journal file should be created. If so, create one and load it. Otherwise choose a journal file to load.

	while (!shouldQuit) {

		char selection;

		printf("Please select an option: \n");

		printf("(n) New Entry, (r) Remove Entry, (l) List Entries, (o) Open Journal File, (q) Quit\n");

		//I don't like having to suppress newline characters this way.
		scanf("%c%*c", &selection);

		switch (selection) {

			case 'n':
				new_entry();
				break;

			case 'r':
				break;

			case 'l':
				list_entries();
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

void new_entry() {

	time_t timestamp = time(NULL);
	FILE *fp;
	char ch;

	Entry new_entry;

	new_entry.timestamp = timestamp;

	printf("Please enter a subject: ");					//Currently unused.
	fgets(new_entry.subject, SUBJECT_LENGTH, stdin);

	printf("Enter your text: \n");


	fgets(new_entry.body, sizeof(new_entry.body), stdin);

	fp = fopen(JOURNAL_FILE, "a");

	if (fp != NULL) {

		fputs(asctime(localtime(&new_entry.timestamp)), fp);
		fputs(new_entry.body, fp);
		fprintf(fp, "\n");
			
	} else {
		
		fprintf(stderr, "File open returned null.\n");
		exit(EXIT_FAILURE);

	}

	printf("\nNew entry added successully!\n\n");

	fclose(fp);

}

//This function will list the latest entry in the journal.
void list_entries() {

	FILE *fp;

	char str[70];

	fp = fopen("journal.lj", "r");

	if (fp != NULL) {

		//TODO
		//READ UNTIL EMPTY LINE OR IDENTIFIER REACHED
		//OUTPUT TO STDIN

		if (fgets(str, 70, fp) != NULL) {
			puts(str);
		}

	
	} else {
		fprintf(stderr, "File open returned null.\n");
		exit(EXIT_FAILURE);
	}

	fclose(fp);

}

//This function will be used to open the journal file in the default text editor.
void open_journal() {

	//Gets the path for the default editor in the environment.
	char *default_editor = getenv("EDITOR");

	//Feels dirty doing it this way but works for now.
	char *opencommand  = strcat(strcat(default_editor, " "), JOURNAL_FILE);
	
	system(opencommand);

}

//TODO: This function will be used to check arguments passed in and utilize them.
void check_args() {

}