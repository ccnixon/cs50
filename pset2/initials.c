#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(void)
{
    string s = GetString();
    if (s != NULL)
    {
        printf("%c", toupper(s[0]));
        for (int i = 1, n = strlen(s); i < n; i++)
        {
            if (s[i] == ' ')
            {
                printf("%c", toupper(s[i + 1]));
            }
        }
        printf("\n");
    }
}