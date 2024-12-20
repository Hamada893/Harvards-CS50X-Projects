// Implements a dictionary's functionality

#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "dictionary.h"

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
} node;

// Choose number of buckets in hash table
const unsigned int N = 26; // Adjust as needed

// Hash table
node *table[N];

// Initialize word count
unsigned int word_count = 0;

// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    // Convert word to lowercase for case-insensitive comparison
    char lower_word[LENGTH + 1];
    for (int i = 0; word[i] != '\0' && i < LENGTH; i++)
    {
        lower_word[i] = tolower(word[i]);
    }
    lower_word[strlen(word)] = '\0'; // Null-terminate the string

    // Hash the word
    unsigned int index = hash(lower_word);

    // Traverse linked list at the hashed index
    for (node *cursor = table[index]; cursor != NULL; cursor = cursor->next)
    {
        if (strncmp(cursor->word, lower_word, LENGTH) == 0)
        {
            return true; // Word found
        }
    }
    return false; // Word not found
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    // Simple hash function (could be improved)
    return tolower(word[0]) - 'a'; // Adjust if needed based on your needs
}

// Loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary)
{
    // Open the dictionary file
    FILE *file = fopen(dictionary, "r");
    if (file == NULL)
    {
        return false; // Could not open the file
    }

    char word[LENGTH + 1];
    // Read each word from the dictionary
    while (fscanf(file, "%s", word) != EOF)
    {
        // Create a new node for the hash table
        node *new_node = malloc(sizeof(node));
        if (new_node == NULL)
        {
            fclose(file);
            return false; // Memory allocation failed
        }
        // Copy the word into the node
        strcpy(new_node->word, word);
        new_node->next = NULL;

        // Hash the word
        unsigned int index = hash(word);

        // Insert the node into the hash table
        new_node->next = table[index];
        table[index] = new_node;

        // Increment the word count
        word_count++;
    }

    fclose(file); // Close the dictionary file
    return true;  // Successfully loaded the dictionary
}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    return word_count; // Return the total word count
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    for (int i = 0; i < N; i++)
    {
        node *cursor = table[i];
        while (cursor != NULL)
        {
            node *temp = cursor;   // Temporary node to hold current
            cursor = cursor->next; // Move to the next node
            free(temp);             // Free the current node
        }
    }
    return true; // Successfully unloaded the dictionary
}
