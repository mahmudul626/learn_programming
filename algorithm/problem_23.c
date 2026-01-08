/**
 * Problem: CamelCase Word Count
 * ----------------------------
 * Task: 
 * Given a string 's' written in CamelCase, determine the total 
 * number of words contained within it.
 * * Rules of CamelCase in this context:
 * 1. The first word is entirely lowercase.
 * 2. Each subsequent word starts with an uppercase letter followed 
 * by lowercase letters.
 * * Logic/Algorithm:
 * 1. Initialize a counter 'count' to 1 (to account for the first 
 * all-lowercase word).
 * 2. Loop through each character of the string starting from the 
 * beginning.
 * 3. Check if the current character is an Uppercase letter 
 * (e.g., if (s[i] >= 'A' && s[i] <= 'Z')).
 * 4. Every time an uppercase letter is found, increment 'count' by 1.
 * 5. Return the final value of 'count'.
 * * Example: "saveChangesInTheEditor"
 * - 's' is lowercase (Initial word: "save") -> count = 1
 * - 'C' is uppercase -> count = 2
 * - 'I' is uppercase -> count = 3
 * - 'T' is uppercase -> count = 4
 * - 'E' is uppercase -> count = 5
 * Final Result: 5
 */


#include <stdio.h>
#include <string.h>

int main() {
    char s[2012875];
    int count = 1;
    scanf("%s", s);
    int length = strlen(s);

    for (int i = 0; i < length; i++)
    {
        if (s[i] >= 'A' && s[i] <= 'Z')
        {
            count ++;
        }
        
    }
    
    
    printf("%d\n", count);


    return 0;
    
}