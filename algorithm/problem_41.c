/*
 * Problem Statement:
 * Write a program that takes an array of n integers, sorts it using the 
 * Insertion Sort algorithm, and prints the state of the array at every 
 * single shifting step (whenever an element is shifted to the right). 
 * Finally, output the completely sorted array.
 *
 * Input:
 * - The first line contains an integer n (size of the array).
 * - The second line contains n space-separated integers (the array elements).
 *
 * Output:
 * - Print the array configuration after each shift operation inside the sorting loop.
 * - Print the final sorted array at the end.
 *
 * Example:
 * Input:
 * 6
 * 1 2 4 6 8 3
 *
 * Output:
 * 1 2 4 6 8 8
 * 1 2 4 6 6 8
 * 1 2 4 4 6 8
 * 1 2 3 4 6 8
 */


#include <stdio.h>
#include <stdlib.h>

int main() {
	int n;
	scanf("%d", &n);
	int *arr = (int *) calloc(n, sizeof(int));
        int temp = 0, j;

	for(int i = 0; i<n; i++) {
		scanf("%d", arr+i);
	}


	for(int i = 0; i<n; i++) {
		temp = arr[i];
		for(j = i-1; j>=0; j--) {
			if(arr[j] > temp) {
				arr[j+1] = arr[j];
			} else {
				break;
			}
			for(int k = 0; k<n; k++) {
				printf("%d ", arr[k]);
			}
			printf("\n");
		}
		arr[j+1] = temp;
	}

	for(int k = 0; k<n; k++) {
                printf("%d ", arr[k]);
        }
	return 0;
}
