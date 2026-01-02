/*
 * Problem: Designer PDF Viewer
 * ----------------------------
 * Description:
 * When you select a contiguous block of text in a PDF viewer, the selection 
 * is highlighted with a blue rectangle. In this viewer, each word is 
 * highlighted independently. 
 *
 * Each character has a specific height (provided in an array of 26 integers).
 * Each character has a fixed width of 1 unit.
 *
 * The area of the highlight rectangle is:
 * Area = (Maximum height of any letter in the word) * (Total number of letters in the word)
 *
 * Input Format:
 * 1. An array 'h' of 26 space-separated integers (heights of 'a' through 'z').
 * 2. A string 'word' (the word to be highlighted).
 *
 * Constraints:
 * - Word length is no more than 10 letters.
 * - Heights are between 1 and 7.
 *
 * Example:
 * Word: "zaba", Heights: a=1, b=3, z=7
 * Max Height: 7 (from 'z')
 * Word Length: 4
 * Area: 7 * 4 = 28
 */



#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {
    



    int n = 26, *arr;
    arr = (int *) malloc(n * sizeof(int));

    for (int i = 0; i < n; i++)
    {
        scanf("%d", arr+i);
    }

    char input[n], charecter[n];
    scanf("%s", input);
    int str_size = strlen(input);
    int ind = 0;
    for (char i = 'a'; i <= 'z'; i++)
    {
        charecter[ind] = i;
        ind ++;
    }
    int max = 0;
    for (int i = 0; i < str_size; i++)
    {
        int str_ind = 0;
        for (int j = 0; j < n; j++)
        {
            if (input[i] == charecter[j] )
            {
                str_ind = j;
            }
            
        }

        if (arr[str_ind] > max)
        {
            max = arr[str_ind];
        }
        
        
    }
    
    int area = max * str_size;
    printf("%d\n", area);
    free(arr);
    
    return 0;
}