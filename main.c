#include <stdio.h>
#include <stdlib.h>
#include "phone.h"

int main(int argc, char **argv) {
    // Create a phone book with an initial size of 10 entries
    Phone_book* pb = (Phone_book*)malloc(sizeof(Phone_book));
    init(pb, 2);

    // Insert a few entries 
    printf("***** Insert few entries *****\n");
    if (!insert(pb, "Taylor Swift", "+36-40-429-6754"))
        printf("Insertion failed\n");
    else printf("Successfully inserted\n");

    if (!insert(pb, "Ed Sheeran", "+36-30-423-7634"))
        printf("Insertion failed\n");
    else printf("Successfully inserted\n");

    // Prints all entries of the phone book
    printf("\n");
    printf("All entries of the phone book:\n");
    print(pb);
    printf("\n");

    // If the name is already in the phone book then the person's phone number should be updated.
    printf("***** Try other cases *****\n");
    printf("\n");
    if (!insert(pb, "Taylor Swift", "+36-40-543-8576"))
        printf("Insertion failed\n");
    else printf("Successfully inserted\n");

    // The insertion is not successful if the array is full
    if (!insert(pb, "Harry Styles", "+36-50-866-9786"))
        printf("Insertion failed\nThe phone book is full\n");
    else printf("Successfully inserted\n");

    // Prints all entries of the phone book
    printf("\n");
    printf("All entries of the phone book:\n");
    print(pb);

    // Prints all entries to a text file
    printf("\n");
    printf("Information can be found in Phonebook.txt");
    dump("Phonebook.txt", pb);

    // Destroy the phone book to avoid memory leak
    destroy(pb);

    return 0;
}