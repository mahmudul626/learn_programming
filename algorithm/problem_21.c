/*
 * Problem: Sequence Equation (Permutation Equation)
 * ------------------------------------------------
 * Given a sequence of n integers p(1), p(2), ..., p(n) where each element 
 * is distinct and satisfies 1 <= p(x) <= n.
 * * Task:
 * For each x where 1 <= x <= n, find an integer y such that p(p(y)) = x.
 * Keep a history of these y values and return them as an array.
 * * Logic:
 * 1. Let x be the current target value (from 1 to n).
 * 2. Find the position 'i' such that p(i) = x.
 * 3. Now, find the position 'y' such that p(y) = i.
 * 4. This 'y' satisfies the condition p(p(y)) = x.
 * * Example:
 * p = [2, 3, 1] (Indices 1, 2, 3)
 * x = 1: p(3)=1, then p(2)=3. So y = 2.
 * x = 2: p(1)=2, then p(3)=1. So y = 3.
 * x = 3: p(2)=3, then p(1)=2. So y = 1.
 * Result: [2, 3, 1]
 * * Constraints:
 * - 1 <= n <= 50
 * - 1 <= p[i] <= n
 * - Each element is distinct.
 */


#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, *arr;
    scanf("%d", &n);
    arr = (int *) malloc(n * sizeof(int));

    for (int i = 0; i < n; i++)
    {
        scanf("%d", arr+i);
    }


    for (int i = 0; i < n; i++)
    {

        int index = 0;
        for (int j = 0; j < n; j++)
        {
            if (*(arr+j) == i+1)
            {

                for(int x = 0; x < n; x++) {
                if (*(arr+x) == j+1)
                {
                    index = x+1;
                    
                }
            }
            }
            
            
            
        }
        printf("%d\n", index);
        
    }
    
    free(arr);
    return 0;
}