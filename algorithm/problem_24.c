/*
 * Problem: Proving Insertion Sort Correctness using Loop Invariant
 * --------------------------------------------------------------
 * A Loop Invariant is a property that holds true before and after each 
 * iteration of a loop. For Insertion Sort, the invariant is:
 * * "At the start of every iteration of the outer loop (indexed with i), 
 * the subarray A[0...i-1] consists of the original elements but in 
 * sorted order."
 * * To prove correctness, we look at three stages:
 * 1. Initialization: Before the first loop (i=1), the subarray A[0...0] 
 * has one element, which is naturally sorted.
 * 2. Maintenance: In each iteration, we find the correct position for A[i] 
 * and shift elements. This maintains the sorted property for A[0...i].
 * 3. Termination: When i equals the array length, the subarray A[0...n-1] 
 * contains all original elements in sorted order.
 * * Task: Fix the error in the Insertion Sort implementation and print 
 * the sorted array once.
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
        for (int j = i +1; j < n; j++)
        {
           if (*(arr+i) > *(arr+j))
           {
            int temp = 0;
            temp = *(arr+i);
            *(arr+i) = *(arr+j);
            *(arr+j) = temp;
           }
           
           
        }
        printf("%d ", arr[i]);
        
    }

    free(arr);
    
    return 0;
}