/**
 * dictionary.c
 *
 * Computer Science 50
 * Problem Set 5
 *
 * Implements a dictionary's functionality.
 */

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "dictionary.h"
#define DICT_SIZE 150000
typedef struct node
{
    char word[LENGTH + 1];
    struct node* next;
}
node;
node* hashtable[DICT_SIZE];
unsigned int words = 0;
unsigned long hash(char *str);
void insert(node* new_node);


/**
 * Returns true if word is in dictionary else false.
 */
 
 
bool check(const char* word)
{
    int length = strlen(word);

    // http://stackoverflow.com/a/20385826/5190914
    char* lower = (char*)malloc(sizeof(length + 1));
    for (int i = 0; i < length; i++)
    {
        lower[i] = tolower(word[i]);
    }

    /* Get hash key for word */
    unsigned long hash_key = hash(lower) % DICT_SIZE;

    /* Check hash table location */
    if (hashtable[hash_key] != NULL)
    {
      node* current_node = hashtable[hash_key];
      do
      {
        if (strcmp(lower, current_node->word) == 0)
        {
          return true;
        }
        current_node = current_node->next;
      }
      while (current_node != NULL);
    }
    
    return false;
}

/**
 * Loads dictionary into memory.  Returns true if successful else false.
 */
bool load(const char* dictionary)
{
    // create file pointer
    FILE* dict = fopen(dictionary, "r");
    
    if (dict == NULL)
    {
        printf("Could not open dictionary\n");
        fclose(dict);
        return false;
    }
    
    char word[LENGTH + 1];
    while (fscanf(dict, "%s", word) != EOF)
    {

      /* Allocate memory to new node */
      node* new_node = malloc(sizeof(node));

      /* Build node */
      strcpy(new_node->word, word);
      new_node->next = NULL;

      /* Add to hash table */
      insert(new_node);
      words++;
      
    }
    fclose(dict);
    return true;
}

/**
 * Returns number of words in dictionary if loaded else 0 if not yet loaded.
 */
unsigned int size(void)
{
    
    return words;
}

/**
 * Unloads dictionary from memory.  Returns true if successful else false.
 */
bool unload(void)
{
    for (int i = 0; i < DICT_SIZE; i++)
    {
        if (hashtable[i] != NULL)
        {
            node* cursor = hashtable[i];
            while (cursor != NULL)
            {
                node* temp = cursor;
                cursor = cursor->next;
                free(temp);
            }
        }
    }
    return true;
}

void insert(node* new_node)
{
  /* Get hash key */
  unsigned long hash_key = hash(new_node->word) % DICT_SIZE;
  
  /* Check if hashtable location has a node */
  if (hashtable[hash_key] == NULL)
  {
    /* If so, add the node and finish */
    hashtable[hash_key] = new_node;
  }
  else
  {
    /* Else, start looping through linked list */
   node* current_node = hashtable[hash_key];
   while (current_node->next != NULL)
   {
    current_node = current_node->next;
   }

   current_node->next = new_node;
  }
}

unsigned long hash(char *str)
{
    unsigned long hash = 5381;
    int c;

    while ((c = *str++))
        hash = ((hash << 5) + hash) + c; /* hash * 33 + c */

    return hash;
}
