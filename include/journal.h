#pragma once
#ifndef JOURNAL_H

#define JOURNAL_H

void new_entry();
void list_latest(int num);
void open_journal();
void write_to_file(char * args);
void remove_journal();

#endif
