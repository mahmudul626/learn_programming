/*Problem: Lonely integer
 *
 * Given an array of integers, where all elements but
 * occur twice. Find the unique element.
 * 
 * Example
 * arr = [1,2,3,4,3,2,1]
 * The unique element is 4.
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {
	int n;
	scanf("%d", &n);
	int *arr = malloc(n * sizeof(int));
	
	for(int i = 0; i<n; i++) {
		scanf("%d", arr+i);
	}
	
	for(int j = 0; j<n; j++) {
		for(int k = j; k<n; k++) {
			if(*(arr+j) == *(arr+k+1)) {
				*(arr+k+1) = 0;
				*(arr+j) = 0;
			}
		}
	}

	for(int m = 0; m<n; m++) {
		if(*(arr+m) > 0) {
			printf("%d", *(arr+m));
		}
	}

	return 0;
}

