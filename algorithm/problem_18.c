/*
An integer is a divisor of another integer if the remainder of the division is 0.  

Given an integer, for each digit that makes up the integer, determine whether it is a divisor.  
Count the number of digits in the integer that are divisors.  

Example 1:  
Check whether 1 and 2 are divisors of 12.  
Both 1 and 2 divide evenly into 12, so return 2.  

Example 2:  
Check whether 1, 0, 1, and 2 are divisors of 1012.  
1, 1, and 2 divide evenly into 1012, but 0 does not (division by zero is undefined).  
Return 3.  

Function Description:  
Complete the findDigits function in the editor below.  

findDigits has the following parameter(s):  
int n: the value to analyze  

Returns:  
int: the number of digits in n that are divisors of n  

Input Format:  
The first line contains an integer, t, the number of test cases.  
Each of the next t lines contains an integer, n.  

Constraints:  
1 <= t <= 15  
0 < n < 10^9  

Sample Input:  
2  
12  
1012  

Sample Output:  
2  
3  

Explanation:  
The number 12 is broken into digits 1 and 2. Both divide 12 evenly.  
The number 1012 is broken into digits 1, 0, 1, and 2. Digits 1, 1, and 2 divide 1012 evenly; 0 is ignored.  
Return the count of divisors for each number.
*/


#include <stdio.h>
#include <stdlib.h>

int main () {
    int n, *arr;
    scanf("%d", &n);
    arr = (int *) malloc(n * sizeof(int));

    for (int i = 0; i < n; i++)
    {
        scanf("%d", arr+i);
    }


    for (int j = 0; j < n; j++)
    {
        int temp = *(arr+j);
        int digit , count = 0;
        while (temp > 0)
        {
           digit = temp % 10;
           if (digit != 0 && *(arr+j) % digit == 0)
           {
                count ++;
           }
           
           temp = temp / 10;
        }
        printf("%d\n", count);
        
    }
    
    return 0;
}