#include <stdio.h>
#include <cs50.h>
#include <math.h>

int main(void)
{
    float change;
    int count = 0;
    do
    {
        printf("How much change is owed?: ");
        change = GetFloat();
    }
    while (change < 0);
    change = round(change * 100);
    while (change > 0)
    {
        if (change - 25 >= 0)
        {
            change -= 25;
            count++;
        }
        else if (change - 10 >= 0)
        {
            change -= 10;
            count++;
        }
        else if (change - 5 >= 0)
        {
            change -= 5;
            count++;
        }
        else
        {
            change -= 1;
            count++;
        }
    }
    printf("%i\n", count);
}