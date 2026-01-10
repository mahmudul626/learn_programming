/*
 * Problem: Jumping on the Clouds (HackerRank)
 * * Description:
 * A player is playing a mobile game with n clouds numbered 0 to n-1. 
 * Some clouds are safe (0) and others are thunderheads (1) which must be avoided.
 * The player can jump from the current cloud to index i+1 or i+2, 
 * provided the destination is a safe cloud.
 * * Goal:
 * Find the minimum number of jumps required to reach the last cloud.
 * * Strategy (Greedy Approach):
 * To minimize the number of jumps, we always attempt to take the largest 
 * step possible (2 clouds ahead). If the cloud at index i+2 is safe, 
 * we jump there. Otherwise, we take a single step to index i+1.
 * Since the problem guarantees the game is always winnable, this 
 * greedy strategy always yields the optimal (minimum) result.
 * * Complexity:
 * Time Complexity: O(n) - We traverse the cloud array once.
 * Space Complexity: O(1) - Only a few variables are used for counting.
 */

#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, *arr, jump = 0;
    scanf("%d", &n);
    arr = (int *) malloc(n * sizeof(int));

    for (int  i = 0; i < n; i++)
    {
        scanf("%d", arr+i);
    }
    
    int i = 0;
    while (i < n -1)
    {
        if (*(arr+i+2) == 1)
        {
            i++;
        } else {
            i+=2;
        }

        jump++;
        
    }
    
    
    printf("%d\n", jump);
    
  free(arr);
    return 0;
}