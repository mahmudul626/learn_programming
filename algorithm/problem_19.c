/* * Problem: Utopian Tree
 * --------------------
 * Description:
 * The Utopian Tree goes through two cycles of growth every year.
 * 1. Spring Cycle: The tree doubles in height (Height * 2).
 * 2. Summer Cycle: The tree increases in height by 1 meter (Height + 1).
 * * The tree is planted as a sapling with an initial height of 1 meter at 
 * the onset of spring (Cycle 0).
 * * Input:
 * - n: The number of growth cycles.
 * * Logic:
 * - Cycle 0: Initial height = 1
 * - Odd Cycles (1, 3, 5...): Spring growth (Double height)
 * - Even Cycles (2, 4, 6...): Summer growth (+1 meter)
 * * Example (n = 4):
 * Cycle 0: 1m (Start)
 * Cycle 1: 1 * 2 = 2m (Spring)
 * Cycle 2: 2 + 1 = 3m (Summer)
 * Cycle 3: 3 * 2 = 6m (Spring)
 * Cycle 4: 6 + 1 = 7m (Summer)
 */


#include <stdio.h>
#include <stdlib.h>

int main() {

    int n, *arr;
    scanf("%d", &n);
    arr = (int *) malloc(n* sizeof(int));

    for (int i = 0; i < n; i++)
    {
        scanf("%d", arr+i);
    }

    for (int i = 0; i < n; i++)
    {

        int height = 1;
        int cycel = 1;
        while (*(arr+i) >= cycel)
        {
          

            if (cycel % 2 == 0)
            {
                
                height += 1;
            } else {
                
                height *= 2;
            }
            
            
            
                
            
            cycel ++;
        }
        
        printf("%d\n", height);
    }

    free(arr);

    return 0;
}