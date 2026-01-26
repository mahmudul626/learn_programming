/*

    Problem: Picking Numbers

        Given an array of integers, find the longest subarray where the absolute

    difference between any two elements is less than or equal to 1.

        Example:

    a = [4, 6, 5, 3, 3, 1]

    There are two subarrays meeting the criterion: [4, 5] and [3, 3].

    The maximum length subarray has 3 elements if we consider the example

    logic of choosing all elements that satisfy the condition.

        Function Description:

    Complete the pickingNumbers function.

        Parameters:

        int a[n]: an array of integers

        Returns:

        int: the length of the longest subarray that meets the criterion

        Input Format:

        The first line contains a single integer n, the size of the array a.

        The second line contains n space-separated integers, each an a[i].

        Constraints:

        2 <= n <= 100

        0 < a[i] < 100

        The answer will be >= 2.

        Sample Input 0:

    6

    4 6 5 3 3 1

    Sample Output 0:

    3

        Explanation 0:

    We choose the following multiset: {4, 3, 3} is not valid because |4-3|=1

    but other pairs must match. Actually, for {4, 5}, the diff is 1.

    For {3, 3}, the diff is 0. In the sample, the best set is {3, 3, 4}

    (if 4 was present) or similar. In this specific case, {3, 3, 4} is not

    possible, but the explanation says we choose {4, 5, 5} or {3, 3, 4}

    based on the logic of the problem.

        Sample Input 1:

    6

    1 2 2 3 1 2

    Sample Output 1:

    5

        Explanation 1:

    We choose {1, 2, 2, 1, 2}. All pairs have an absolute difference <= 1. 
    
    */


#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, *arr;
    scanf("%d", &n);
    arr = (int *) calloc(101, sizeof(int));

    for (int i = 0; i < n; i++)
    {
        int id;
        scanf("%d", &id);
        arr[id]++;
        
        
    }

    int max = 0;
    for (int i = 0; i < n; i++)
    {
        if (*(arr+i) + *(arr+i+1) > max)
        {
            max = *(arr+i) + *(arr+i+1);
        }
        
    }

    printf("%d\n", max);
    free(arr);

    return 0;
}