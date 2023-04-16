#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>
#include<time.h>
#include<unistd.h>
#include "../include/fileio.h"

#define JOURNAL_FILE "journal.lj"
//Dynamically allocate this later so that the length of entries is not hardcoded.
#define MAX_LENGTH 255

//This struct is used to store input temporarilty before it is written to the journal file.
typedef struct {

	//TODO: The length of the body needs to be dynamically allocated at runtime.
	char body[MAX_LENGTH];
	time_t timestamp;

} Entry;

//TODO: Move this to journal.c. Makes more sense for general initialization to happen there.
bool check_journal() {

    //NOTE: access() is POSIX standard but NOT C standard. Consider revising for portability.
    if (access("../bin/journal.lj", F_OK)) {
        return false;
    } else {
        return true;
    }

}

//Function prototypes
char * get_time(Entry entry);
void write_to_file();

//Stores user input into the journal file when invoked.
void new_entry() {

	printf("Enter your text (Max 255 characters.): \n");

	write_to_file(NULL);

}

//This function will list the latest entry in the journal.
void list_latest(int num) {

	FILE *fp;

	char str[MAX_LENGTH];

	fp = fopen("journal.lj", "r");

	if (fp != NULL) {

		//TODO: Do not hardcode length here. Change once strings are dynamically allocated.
		if (fgets(str, 255, fp)) {
			printf("\n%s\n", str);
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

//Used to modify the timestamp obtained on new entry.
char *get_time(Entry entry) {

	//Convert time_t type to string.
	char *timeString = asctime(localtime(&entry.timestamp));
	
	//Remove newline character (\n) added by asctime()
	//NOTE: The final element of the char array will be null! Fix later dynamically!
	timeString[strlen(timeString) - 1] = 0;

	return timeString;

}

//Writing to file will be refactored into here so that command line arguments can be used to write entries.
void write_to_file(char * args) {

	time_t timestamp = time(NULL);
	Entry new_entry;

	FILE *journal = open_file("a");

	new_entry.timestamp = timestamp;

	if (args == NULL) {
		fgets(new_entry.body, sizeof(new_entry.body), stdin);
	} else {
		strcpy(new_entry.body, args);
		strcat(new_entry.body, "\n");
	}
	
	//NOTE: Checking for null pointers takes place in fileio. Seeing if redundancy is needed here.
	fputs(get_time(new_entry), journal);
	fputs("   ", journal);
	fputs(new_entry.body, journal);
	fprintf(journal, "\n");
			
	printf("\nNew entry added successully!\n\n");

	close_file(journal);

}

//Deletes the user's journal file.
void remove_journal() {

	char choice;

	printf("Are you certain you wish to delete your journal file? (This cannot be undone!) (y/n): ");

	//TODO: Make sure the journal file exists first. If so, delete, otherwise, throw an error.
	if ((choice = getchar()) == 'y') {

		system("rm journal.lj");
		printf("Journal file removed successfully.\n");

	} else {

		printf("Journal removal cancelled.\n");
		return;

	} 

}

// char *handle_input() {

// #define	BUFFER 200

// 	char *user_input = NULL;
// 	char input_buffer[BUFFER];

// 	size_t input_length = 0; temp_length = 0;

// 	do {
// 		fgets(input_buffer, BUFFER, stdin);
// 		temp_length = strlen(input_buffer);
// 		user_input = realloc(user_input, input_length + temp_length + 1);
// 		strcpy(user_input + input_length, input_buffer);
// 		input_length += temp_length;

// 	} while (temp_length == BUFFER - 1 && input_buffer[BUFFER - 2] != '\n');
	
// 	return user_input;

// }