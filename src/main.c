#include<stdio.h>
#include<stdbool.h>
#include<stdint.h>
#include<stdlib.h>
#include<string.h>
//TODO: Dynamically allocate this if necessary.
#define NAME_LENGTH 100

//This struct is used to temporarily store new entries before they are written to the journal file.
typedef struct {

	char name[NAME_LENGTH];
	char body[255];

} Entry;

//Prototypes
void new_entry(char * entry_name);

int main(int argc, char **argv) {

	bool shouldQuit = false;

	printf("Welcome to litejournal 0.01!\n\n");
	printf("Default journal loaded...\n\n");

	//TODO: Check if a new journal file should be created. If so, create one and load it. Otherwise choose a journal file to load.

	while (!shouldQuit) {

		char selection;

		printf("Please select an option: \n");

		printf("(n) New Entry, (r) Remove Entry, (l) List Entries, (q) Quit\n");

		//I don't like having to suppress newline characters this way.
		scanf("%c%*c", &selection);

		switch (selection) {

			case 'n':

				printf("Please enter an entry name: ");
				char entry_name[NAME_LENGTH]; 
				fgets(entry_name, NAME_LENGTH, stdin);
				new_entry(entry_name);
				break;

			case 'r':
				break;

			case 'l':
				break;

			case 'q':
				shouldQuit = true;
				break;
			default:
				printf("\nIncorrect selection specified. ");

		}

	}

	return 0;

}

void new_entry(char * entry_name) {

	FILE *fp;
	char ch;

	Entry new_entry;

	printf("Enter your text: \n");


	fgets(new_entry.body, sizeof(new_entry.body), stdin);

	fp = fopen("journal.lj", "w");

	if (fp != NULL) {

		fputs(new_entry.body, fp);	
	
	} else {
		
		fprintf(stderr, "File open returned null.\n");
		exit(EXIT_FAILURE);

	}

	printf("\nNew entry added successully!\n\n");

	fclose(fp);

}

void list_entries() {


	
}