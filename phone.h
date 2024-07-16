#ifndef PHONE_H
#define PHONE_H
#define NAME_CAPACITY 30
#define PHONE_CAPACITY 30

#include <stdbool.h>

struct Entry
{
    char name[NAME_CAPACITY];
    char phone[PHONE_CAPACITY];
};

typedef struct Entry Entry;

struct Phone_book
{
    Entry* entries;
    int size;
    int num_entries;
};

typedef struct Phone_book Phone_book;

void init(Phone_book* pb, int size);
void destroy(Phone_book* pb);
bool insert(Phone_book* pb, const char* name, const char* phone);
Entry* get(const char* name, Phone_book* pb);
void print(Phone_book* pb);
void dump(const char* file_name, Phone_book* pb);

#endif