#include <stdio.h>
#include <cs50.h>

int main(void)
{
    printf("minutes: ");
    int x = GetInt();
    printf("%i\n", (x * 192) / 16);
}