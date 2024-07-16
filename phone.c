#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "phone.h"

// Create an init() function which initializes the phone book. This function has an integer parameter which determines the size of the entries' array. An array with this size should be allocated on the heap memory.
void init(Phone_book* pb, int size) {
    pb->entries = (Entry*) malloc(size * sizeof(Entry));
    pb->size = size;
    pb->num_entries = 0;
}

// Implement a corresponding destroy() in order to avoid memory leak.
void destroy(Phone_book* pb) {
    free(pb->entries);
    free(pb);
}

// Create a get() function which is given a name and returns the phone number of this person.
// If the person is not found in the phone book then NULL pointer should return.
// check
Entry* get(const char* name, Phone_book* pb)
{
    for (int i = 0; i < pb->num_entries; i++) 
    {
        if (strcmp(pb->entries[i].name, name) == 0) {
            return &(pb->entries[i]);
        }
    }
    return NULL;
}

// Create an insert() function which is given a name and a phone number.
// These should be inserted to the phone book.
// If the name is already in the phone book then the person's phone number should be updated.
// The insert() function should return a boolean value depending on whether the insertion was successful.
bool insert(Phone_book* pb, const char* name, const char* phone) {
    Entry* e = get(name, pb);
    if (e)
    {
        strcpy(e->phone, phone);
        return true;
    }

    // The insertion is not successful if the array is full.
    if (pb->num_entries == pb->size)
        return false;

    // If the name doesn't exist, add it to the end of the array
    strcpy((pb->entries + pb->num_entries)->name, name);
    strcpy((pb->entries + pb->num_entries)->phone, phone);
    pb->num_entries++;

    return true;
}

// Create a print() function which prints all entries of the phone book
void print(Phone_book* pb)
{
    for (int i = 0; i < pb->num_entries; i++) 
    {
        printf("%s\t%s\n", pb->entries[i].name, pb->entries[i].phone);
    }
}

// Create a dump() function which prints all entries to a text file.
// The text file's name should be given as a parameter to this function.
void dump(const char* file_name, Phone_book* pb)
{
    FILE* f;
    f = fopen(file_name, "w");
    if (f != NULL)
    {
        for (int i = 0; i < pb->num_entries; i++) 
        {
            fprintf(f, "%s\t%s\n", pb->entries[i].name, pb->entries[i].phone);
        }
    }
    fclose(f);
    f=NULL;
}