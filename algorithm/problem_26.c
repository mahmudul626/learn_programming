/*
Problem Name: Cut the Sticks
Platform: HackerRank (Problem Solving → Algorithms → Implementation)

Problem Summary:
You are given an array of integers where each integer represents
the length of a stick.

The task is to repeatedly cut the sticks until no sticks remain.

Rules of the process:
1. At each iteration, find the shortest stick length among the remaining sticks.
2. Cut that length from every stick that is longer than the shortest one.
3. Discard all sticks that become zero length after the cut.
4. Before each cut, print (or store) the number of sticks currently remaining.
5. Stop when no sticks are left.

Important Notes:
- The order of sticks does not matter.
- Only positive-length sticks are considered in each iteration.
- When all remaining sticks have the same length, they are discarded in the next step.

Input:
- An integer n, the number of sticks.
- An array arr of size n, where arr[i] is the length of the i-th stick.

Output:
- An array (or printed values) where each element represents
  the number of sticks before each cut operation.

Example:
Input:
arr = [5, 4, 4, 2, 2, 8]

Process:
Iteration 1:
- Shortest stick = 2
- Sticks before cut = 6
- Remaining lengths after cut = [3, 2, 2, 6]

Iteration 2:
- Shortest stick = 2
- Sticks before cut = 4
- Remaining lengths after cut = [1, 4]

Iteration 3:
- Shortest stick = 1
- Sticks before cut = 2
- Remaining lengths after cut = [3]

Iteration 4:
- Shortest stick = 3
- Sticks before cut = 1
- All sticks discarded

Final Output:
6
4
2
1

Core Idea (Logic Explanation):
- Sort the array (optional but helpful).
- Count how many sticks are still greater than zero.
- Each time the minimum positive value changes,
  the count of remaining sticks decreases.
- Print or store the count before each reduction step.

This problem mainly tests:
- Array manipulation
- Iterative reduction logic
- Understanding of simulation-based algorithms
- Handling edge cases (duplicate values, all equal values)

Time Complexity Insight:
- Sorting helps reduce complexity.
- Overall complexity is efficient for given constraints.

This solution focuses on clarity and correctness rather than advanced optimization.
*/


#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, *arr;
    scanf("%d", &n);
    arr = (int *) malloc(n* sizeof(int));
    
    for (int i  = 0; i < n; i++) {
        
        scanf("%d", arr+i);
    
    }
    
    for (int i = 0; i < n - 1; i++) {
        
        for (int j = 0; j < n - i - 1; j++) {
            
            if (*(arr+j) > *(arr+j+1)) {
                
                int temp = 0;
                temp = *(arr+j);
                *(arr+j) = *(arr+j+1);
                *(arr+j+1) = temp;
            
            }
        
        }
    
    }
    printf("%d\n", n);
    
    for (int k = 1; k < n; k++) {
        
        if (*(arr+k) != *(arr+k-1)) {
            printf("%d\n", n-k);
        }
    
    }
    free(arr);
    return 0;
}