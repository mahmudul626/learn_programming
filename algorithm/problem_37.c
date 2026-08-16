/* 

* HackerRank Problem: Flipping Bits
* 
* Problem Description:
* You will be given a list of 32-bit unsigned integers.
* You need to flip all the bits (change 1 to 0 and 0 to 1)
* and return the result as an unsigned integer.
* 
* Example:
* n = 9 (in 32-bit: 00000000000000000000000000001001)
* After flipping bits: 11111111111111111111111111110110
* Output: 4294967286
*/

#include <stdio.h>
#include <math.h>

int main() {
	int d;
	int size = 32;
	scanf("%d", &d);
	int arr[size];

	for(int i = 0; i<size; i++) {
		arr[i] = d % 2;
		d /= 2;
	}

        for(int j = 0; j < size; j++) {
                arr[j] ^= 1;
        }

        unsigned int ans = 0;

        for(int k = 0; k<size; k++) {
                ans += (pow(2,k) * arr[k]) * arr[k];
        }

        printf("%u", ans);
	return 0;
}
