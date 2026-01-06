/**
 * Challenge: Intro to Tutorial Challenges - Sorting
 * Platform: HackerRank
 * * Description:
 * This is a foundational search problem. Given a value (V) and a sorted 
 * array of integers (arr), the goal is to find the zero-based index 
 * where the value V is located.
 * * Key Points:
 * - Input: An integer V, the size of the array n, and the sorted array arr.
 * - Output: The index of V in the array.
 * - Constraints: V is guaranteed to be in the array exactly once.
 * - Algorithm: Since the array is sorted, a Linear Search (O(n)) works, 
 * but Binary Search (O(log n)) is more efficient for large datasets.
 * * Sample Input:
 * V = 4, arr = [1, 4, 5, 7, 9, 12]
 * Sample Output:
 * 1 (because arr[1] is 4)
 */


#include <stdio.h>
#include <stdlib.h>


int main() {
    int v,n,*arr;
    scanf("%d", &v);
    scanf("%d", &n);
    arr = (int *) malloc(n * sizeof(int));

    for (int i = 0; i < n; i++)
    {
        scanf("%d", arr+i);
    }

    for (int j = 0; j < n; j++)
    {
        if (v == *(arr+j))
        {
            printf("%d\n", j);
        }
        
    }
    free(arr);
    return 0;
}