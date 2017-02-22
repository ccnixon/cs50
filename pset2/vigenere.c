#include <stdio.h>
#include <string.h>
#include <cs50.h>
#include <stdlib.h>
#include <ctype.h>

int main(int argc, string argv[])
{
    if (argc != 2)
    {
        printf("Please input a word as an argument.\n");
        return 1;
    }
    string key = argv[1];
    int key_len = strlen(key);
    
    //Check that all characters are letters
    for (int i = 0; i < key_len; i++)
    {
        char c = key[i];
        if (!isalpha(c))
        {
            printf("Please do not use any non alphabetic characters in your key.\n");
            return 1;
        }
        // Move key values to lowercase
        else
        {
            key[i] = tolower(key[i]);   
        }
        
    }
    string plaintext = GetString();
    int shift_key_counter = 0;
    for (int i = 0, n = strlen(plaintext); i < n; i++)
    {
        char currLetter = plaintext[i];
        int shift_key = key[shift_key_counter % key_len] - 97;
        // printf("%i\n", shift_key);
        int asciiStartValue;
        if (isalpha(currLetter))
        {
            if (islower(currLetter))
            {
                asciiStartValue = 97;
            }
            else
            {
                asciiStartValue = 65;
            }
            
            // Get int version of currLetter
            int c = ((int) currLetter);
            
            //Convert currLett to normal alphabet position and add key value
            c = (c - asciiStartValue + shift_key) % 26;
            
            //Convert back to ASCII
            c = (c + asciiStartValue);
            
            printf("%c", (char) c);
            shift_key_counter++;
        }
        else 
        {
            printf("%c", currLetter);
        }
    }
    printf("\n");
    return 0;
}