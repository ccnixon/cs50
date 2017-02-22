#include <stdio.h>
#include <cs50.h>

int main(void)
{
    int height;
    do
    {
        printf("height: ");
        height = GetInt();
    }
    while (height <= 0 || height > 23);
    
    for (int i = 0; i < height; i++)
    {
        // print spaces
        for (int j = 0; j < height - i - 1; j++)
        {
            printf("%s", " ");
        }
        // print hashes
        for (int k = 0; k < i + 2; k++)
        {
            printf("#");
        }
        printf("\n");
    }
}