/*
Problem Name: Sum Xor
Platform: HackerRank

Problem Description:
Given an integer n, find the number of integers i such that:
0 <= i <= n and (n + i) == (n ^ i)

Explanation:
1. The condition (n + i) == (n ^ i) is only true if n and i share no common set bits (n & i == 0).
2. For every bit in n that is 1, the corresponding bit in i must be 0 (1 choice).
3. For every bit in n that is 0, the corresponding bit in i can be either 0 or 1 (2 choices).
4. Therefore, the total number of valid values for i is 2 raised to the power of the number of unset bits (zeros) in n.
   Formula: 2^(count of zeros)

Complexity:
- Time Complexity: O(log n)
- Space Complexity: O(1)

Example:
input - 10
output- 4
----------
input - 5
output- 2
*/


#include <stdio.h>

long sumXor(long n) {
    
    int count = 0;
    while(n > 0) {
        if((n&1) == 0) count++;
        n>>=1;
    }   
    return 1L<<count;
}

int main(void) {
	long num;
	scanf("%ld", &num);
	printf("%ld\n", sumXor(num));
	return 0;
}
