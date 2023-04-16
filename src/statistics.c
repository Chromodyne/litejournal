#include<stdio.h>
#include<stdbool.h>
#include<stdint.h>
#include<unistd.h>
#include "../include/journal.h"

//File will be used to handle statistics keeping for journal. Mostly for fun!

struct Stats {
    uint32_t numEntries;
    uint32_t longestEntry;
    uint32_t streak;
} stats;

void initialize_stats() {

    if (check_journal()) {

        printf("Journal exists.");

    } else {

        printf("Journal DNE.");
        stats.numEntries = 0;
        stats.longestEntry = 0;
        stats.streak = 0;

    }

}

void save_stats() {

}