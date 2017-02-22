#include <stdio.h>
#include <string.h>
#include <cs50.h>
#include <stdlib.h>
#include <ctype.h>

int main(int argc, string argv[])
{
    if (argc != 2)
    {
        printf("Please input a single integer as an argument\n");
        return 1;
    }
    string key_string = argv[1];
    int key = atoi(key_string);
    string s = GetString();
    for (int i = 0, n = strlen(s); i < n; i++)
    {
        char currLetter = s[i];
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
            
            //Convert it to normal alphabet position and add key value
            c = (c - asciiStartValue + key) % 26;
            
            //Convert back to ASCII
            c = (c + asciiStartValue);
            
            printf("%c", (char) c);
        }
        else 
        {
            printf("%c", currLetter);
        }
    }
    printf("\n");
    return 0;
}