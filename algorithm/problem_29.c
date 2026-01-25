/**
 * Problem: Migratory Birds
 * ------------------------
 * Goal: Find the bird type ID with the highest frequency. If multiple types 
 * have the same maximum frequency, return the smallest ID among them.
 * * Logic & Approach:
 * 1. Constraints Check: The bird IDs are guaranteed to be 1, 2, 3, 4, or 5.
 * This allows us to use a fixed-size array (e.g., size 6) to store counts, 
 * where the index represents the bird ID.
 * * 2. Frequency Mapping: 
 * - Initialize an integer array `counts[6]` with zeros.
 * - Iterate through the input array `arr`.
 * - For every sighting `x`, increment `counts[x]`.
 * * 3. Finding the Result:
 * - Initialize `max_frequency = 0` and `result_id = 0`.
 * - Iterate from index 1 to 5 (the possible bird IDs).
 * - If `counts[i]` is strictly GREATER than `max_frequency`:
 * - Update `max_frequency` to `counts[i]`.
 * - Update `result_id` to `i`.
 * - Note: By iterating from 1 to 5 and using a strict "greater than" 
 * comparison, we naturally satisfy the requirement to pick the smallest 
 * ID in case of a tie.
 * * Example 1 (Sample Input 1):
 * Input: [1, 2, 3, 4, 5, 4, 3, 2, 1, 3, 4]
 * Frequencies: Type 1:2, Type 2:2, Type 3:3, Type 4:3, Type 5:1
 * Max frequency is 3 (held by types 3 and 4).
 * Result: 3 (the smaller ID).
 * * Complexity:
 * - Time: O(n) - We traverse the input array once.
 * - Space: O(1) - We use a fixed-size auxiliary array of 6 integers.
 */


#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, *count;
    scanf("%d", &n);
    count = (int *) calloc(6, sizeof(int));

    for (int i = 0; i < n; i++)
    {
        int id;
        scanf("%d", &id);
        count[id]++;
    }

    int max = 0;
    int id = 0;
    for (int i = 0; i <=5 ; i++)
    {
        if (max < *(count+i))
        {
            max = *(count+i);
            id = i;
        }
        
    }
    
    printf("%d\n", id);
    free(count);
    return 0;
    
}