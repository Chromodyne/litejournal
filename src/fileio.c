#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>

FILE *open_file(char * operation) {

    FILE *fp;

    fp = fopen("journal.lj", operation);

    if (fp != NULL) {
        return fp;
    } else {
        fprintf(stderr, "File open returned null.\n");
        exit(EXIT_FAILURE);
    }

}

void close_file(FILE * fp) {

    fclose(fp);

}
