/**
 * helpers.c
 *
 * Computer Science 50
 * Problem Set 3
 *
 * Helper functions for Problem Set 3.
 */
       
#include <cs50.h>
#include <stdio.h>
#include "helpers.h"

void print_array(int values[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%i\n", values[i]);
    }
}

/**
 * Returns true if value is in array of n values, else false.
 * 
 */

int binary_search(int value, int values[], int min, int max)
{
    if (max < min)
    {
        return -1;
    }
    int midpoint = (min + max) / 2;
    if (values[midpoint] < value)
    {
        return binary_search(value, values, midpoint + 1, max);
    }
    else if (values[midpoint] > value)
    {
        return binary_search(value, values, min, midpoint - 1);
    }
    return values[midpoint];
}

bool search(int value, int values[], int n)
{
    // TODO: implement a searching algorithm
    int min = 0;
    int max = n - 1;
    int result = binary_search(value, values, min, max);
    if (result == value)
    {
        return true;
    }
    return false;
}

/**
 * Sorts array of n values.
 */
void sort(int values[], int n)
{
    
    // TODO: implement an O(n^2) sorting algorithm
    for (int i = 0; i < n - 1; i++)
    {
        int min = values[i];
        for (int j = i + 1; j < n; j++)
        {
            if (values[j] < min)
            {
                min = values[j];
                values[j] = values[i];
                values[i] = min;
            }
        }
    }
    return;
}
