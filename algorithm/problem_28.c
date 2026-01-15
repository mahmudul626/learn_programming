/*
Problem: Beautiful Days at the Movies

Lily defines a "beautiful number" based on the following logic:
1. Take an integer 'x'.
2. Reverse the digits of 'x' to get 'reverse(x)'.
3. Calculate the absolute difference: |x - reverse(x)|.
4. If this difference is evenly divisible by a given divisor 'k', 
   the number is "beautiful".

Task:
Given a range of days [i, j] and a divisor 'k', count how many 
days in the range (inclusive) are beautiful.

Example:
Input: i=20, j=23, k=6
- Day 20: |20 - 02| = 18. 18 / 6 = 3.0 (Beautiful)
- Day 21: |21 - 12| = 9.  9 / 6 = 1.5  (Not Beautiful)
... and so on.
*/

#include <stdio.h>
#include <stdlib.h>


int main() {
    int n,m,k,day = 0;
    scanf("%d %d %d", &n,&m,&k);


    for (int i = n; i <= m; i++)
    {
        int rev = 0;
        int current = i;
        while (current != 0)
        {
            int temp = current % 10;
            rev = (rev * 10) + temp;
            current /= 10;
        }

        int diff = abs(i - rev);
        if (diff % k == 0)
        {
            day++;
        }
        

        
        
        
    }
    
    printf("%d\n", day);
    return 0;
}