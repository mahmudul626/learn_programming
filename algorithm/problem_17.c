/*
 * Problem: Equalize the Array
 * * Description:
 * Given an array of integers, determine the minimum number of elements 
 * to delete to leave only elements of equal value.
 * * Example:
 * arr = [1, 2, 2, 3]
 * There are two 2's, one 1, and one 3. 
 * If we keep the 2's, we need to delete the 1 and the 3 (2 deletions).
 * If we keep the 1, we need to delete the two 2's and the 3 (3 deletions).
 * The minimum number of deletions is 2.
 * * Strategy:
 * 1. Count the frequency of each number in the array.
 * 2. Find the maximum frequency (the number that appears most often).
 * 3. Min Deletions = Total length of array - Maximum frequency.
 * * Returns:
 * - int: the minimum number of deletions required.
 */

#include <stdio.h>
#include <stdlib.h>


int main() {
    int n, *arr, max_count = 0;
    scanf("%d", &n);
    arr = (int *) malloc(n * sizeof(int));

    for (int i = 0; i < n; i++)
    {
        scanf("%d", arr+i);
    }


    for (int i = 0; i < n; i++)
    {
        int count = 0;
        for (int j = 0; j < n; j++)
        {
            if (*(arr+i) == *(arr+j)) count++;
        }
        if (max_count < count) max_count = count;
    }

    printf("%d", n-max_count); // Minimum Deletions = Total Elements (n) − Max Frequency (max_count)
    
    return 0;
}