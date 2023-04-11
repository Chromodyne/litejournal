#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#include<unistd.h>

#define SUBJECT_LENGTH 100
#define JOURNAL_FILE "journal.lj"

//This struct is used to store input temporarilty before it is written to the journal file.
typedef struct {

	char subject[SUBJECT_LENGTH];

	//TODO: The length of the body needs to be dynamically allocated at runtime.
	char body[255];
	time_t timestamp;

} Entry;

//Function prototypes
char * get_time(Entry entry);

//Stores user input into the journal file when invoked.
void new_entry() {

	time_t timestamp = time(NULL);
	
	FILE *fp;

	Entry new_entry;

	new_entry.timestamp = timestamp;

	//printf("Please enter a subject: ");					//Currently unused.
	//fgets(new_entry.subject, SUBJECT_LENGTH, stdin);

	//TODO: Store timestamp and content on same line so newlines can be used to identify separate entries.

	printf("Enter your text (Max 255 characters.): \n");

	fgets(new_entry.body, sizeof(new_entry.body), stdin);

	fp = fopen(JOURNAL_FILE, "a");

	if (fp != NULL) {

		fputs(get_time(new_entry), fp);
		fputs("   ", fp);
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
void list_latest() {

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

//Used to modify the timestamp obtained on new entry.
char *get_time(Entry entry) {

	//Convert time_t to string.
	char *timeString = asctime(localtime(&entry.timestamp));
	
	//Remove newline character (\n) added by asctime()
	//NOTE: The final element of the char array will be null!
	timeString[strlen(timeString) - 1] = 0;

	return timeString;

}