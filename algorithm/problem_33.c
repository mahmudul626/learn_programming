/* Problem: Insertion Sort Part 2

   Goal:
   Using the approach of inserting one element into a sorted array,
   sort an entire array. You already know how to insert a single element
   at its correct position in a sorted portion of an array.

   Instructions:
   - Start from the second element of the array (index 1)
     because the first element is trivially sorted.
   - Take each element and insert it into the correct position
     among the elements to its left (the sorted portion).
   - After inserting each element, print the array as
     space-separated integers on its own line.
   - Continue this process until the entire array is sorted.

   Example:

   Input:
     6
     1 4 3 5 6 2

   Output:
     1 4 3 5 6 2
     1 3 4 5 6 2
     1 3 4 5 6 2
     1 3 4 5 6 2
     1 2 3 4 5 6

   Notes:
   - Begin printing after placing the second element, 
     since the first element alone is already sorted.
   - Think of building a sorted array one element at a time.
   - You only need to print after each insertion, not every comparison.
   - Do not modify the input or output format.
   - Constraints and input/output are standard: integer array of size n.
*/




#include <stdio.h>
#include <stdlib.h>


int main() {
    int n, *arr;
    scanf("%d", &n);
    arr = (int *) malloc(n * sizeof(int));

    for (int  i = 0; i < n; i++)
    {
        scanf("%d", arr+i);
    }
    


    for (int i = 1; i < n; i++)
    {
       int ind = arr[i];
       int j = i - 1;
        
       while (j >= 0 && arr[j] > ind)
       {
            arr[j + 1] = arr[j];
            j--;
            
            
       }

       arr[j + 1] = ind;

       for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
       
    }
    
    free(arr);
    
    return 0;
}