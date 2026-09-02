/*
 * Problem Name: Find the Median
 * Platform: HackerRank (Algorithms -> Sorting)
 * 
 * Problem Statement:
 * The median of a list of numbers is essentially its middle element after sorting. 
 * The same number of elements occur after it as before. Given a list of numbers 
 * with an odd number of elements, find the median.
 *
 * Function Description:
 * Complete the findMedian function.
 * - Parameter: int arr[n] (an unsorted array of integers)
 * - Returns: int (the median of the array)
 *
 * Input Format:
 * - The first line contains the integer n, the size of arr.
 * - The second line contains n space-separated integers.
 *
 * Constraints:
 * - n is odd
 *
 * Sample Input:
 * 7
 * 0 1 2 4 6 5 3
 *
 * Sample Output:
 * 3
 *
 * Explanation:
 * The sorted array is 0 1 2 3 4 5 6. Its middle element is 3.
 */

#include <stdio.h>
#include <stdlib.h>

int cmp(const void *a, const void *b) {
	return *(int *)a - *(int *)b;
}

int main() {
	int arr_count;
	scanf("%d", &arr_count);
	int *arr = (int *) calloc(arr_count, sizeof(int));
	for(int i = 0; i<arr_count; i++)
		scanf("%d", arr+i);
	int ans = 0;
	qsort(arr, arr_count, sizeof(int), cmp);

    	if(arr_count == 1) {
        	ans = arr[0];
    	} else {
        	int d = (arr_count-1) / 2;
        	ans = arr[d];
    	}

	printf("%d\n", ans);
	return 0;
}
