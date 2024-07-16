# Phone Book Application

This project involves creating a phone book application that stores a list of (name, phone number) pairs. The application includes functions to initialize the phone book, insert entries, retrieve phone numbers, print entries, and dump the entries to a text file. This README provides an overview of the implementation.

## Project Structure

- **Entry Struct**: Represents an entry with a name and a phone number, both as 30-character arrays.
- **PhoneBook Struct**: Contains a pointer to an array of entries, the number of inserted elements, and the actual size of the array.
- **Functions**:
  - `init()`: Initializes the phone book.
  - `destroy()`: Deallocates the memory allocated for the phone book.
  - `insert()`: Inserts or updates a name and phone number in the phone book.
  - `get()`: Retrieves the phone number for a given name.
  - `print()`: Prints all entries in the phone book.
  - `dump()`: Writes all entries to a text file.

## PhoneBook Struct

- **Entry Struct**:
  - Contains two 30-character arrays: one for the name and one for the phone number.
- **PhoneBook Struct**:
  - Contains a pointer to an array of entries.
  - Contains an integer for the number of inserted elements.
  - Contains an integer for the actual size of the array.

## Functions

- `init(int size)`: Initializes the phone book by allocating memory for the entries' array on the heap. The size of the array is determined by the parameter. It also initializes the count of inserted elements to 0.

- `destroy()`: Deallocates the memory allocated for the entries' array to prevent memory leaks.

- `insert(const char *name, const char *phone)`: Inserts a name and phone number into the phone book. If the name already exists, it updates the phone number. It returns a boolean value indicating whether the insertion was successful. The insertion fails if the array is full.

- `get(const char *name)`: Retrieves the phone number for a given name. Returns a NULL pointer if the name is not found.

- `print()`: Prints all entries in the phone book to the console.

- `dump(const char *filename)`: Writes all entries to a text file. The file name is given as a parameter to this function.

## Usage

1. Initialize a phone book with a specified size.
2. Insert several (name, phone number) pairs into the phone book.
3. Retrieve and print a phone number by name.
4. Print all entries in the phone book to the console.
5. Dump all entries to a specified text file.
6. Destroy the phone book to deallocate memory.

## Example Workflow

1. **Initialization**: Create a phone book with a specified size.
2. **Insertion**: Add new entries or update existing ones.
3. **Retrieval**: Get the phone number associated with a specific name.
4. **Printing**: Display all phone book entries on the screen.
5. **Dumping**: Write all phone book entries to a text file.
6. **Cleanup**: Free the allocated memory when done.

Ensure that the application handles all edge cases and avoids undefined behavior. Proper memory management and error handling are essential for preventing memory leaks and ensuring robustness.
