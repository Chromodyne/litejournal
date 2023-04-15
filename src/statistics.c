#include<stdio.h>
#include<stdbool.h>
#include<stdint.h>
#include<unistd.h>

//File will be used to handle statistics.

struct Stats {

    uint32_t numEntries;
    uint32_t longestEntry;
    uint32_t streak;

} stats;


bool check_journal() {

    bool firstRun = true;

    //NOTE: POSIX standard but NOT C standard. Consider revising for portability.
    if (access("../bin/journal.lj", F_OK)) {

        firstRun = false;

    } else {

        firstRun = true;

    }

    return firstRun;

}

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