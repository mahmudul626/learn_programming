/*
 * Problem Name: Running Time of Algorithms (Insertion Sort Shifts)
 * * Objective:
 * Insertion Sort algorithm use kore ekta array sort korar somoy 
 * mot koto gulo 'shift' (positing change) korte hoy seta count kora.
 * * Logic:
 * 1. Array-er 2nd element theke loop shuru korte hobe.
 * 2. Protiti element (key)-ke tar bam pasher sorted element-gular sathe compare korte hobe.
 * 3. Jodi bam pasher element-ti 'key' er cheye boro hoy, tobe seta-ke ek ghor 
 * daane shift korte hobe (arr[j+1] = arr[j]).
 * 4. Protibar jokhon e ei shift hobe, amader 'shift_count' variable-ti 1 kore barate hobe.
 * 5. Shob sheshe 'shift_count' return korte hobe.
 * * Time Complexity:
 * - Best Case: O(n) [Jodi array age thekei sort kora thake, shift hobe 0]
 * - Worst Case: O(n^2) [Jodi array reverse order e thake]
 * * Sample Explanation:
 * Input: [2, 1, 3, 1, 2]
 * - 1 ke shift korle: [1, 2, 3, 1, 2] -> 1 shift
 * - 3 ke shift korte hoy na -> 0 shift
 * - 1 ke shift korle (3 ebong 2 er pashe): [1, 1, 2, 3, 2] -> 2 shifts
 * - 2 ke shift korle (3 er pashe): [1, 1, 2, 2, 3] -> 1 shift
 * Total shifts = 1 + 0 + 2 + 1 = 4.
 */

// Function Structure (Logical Idea):
/*
int runningTime(int n, int arr[]) {
    int shifts = 0;
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j]; // Shifting
            j--;
            shifts++; // Increment shift count
        }
        arr[j + 1] = key;
    }
    return shifts;
}
*/

#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, *arr;
    scanf("%d", &n);

    arr = (int *) malloc(n * sizeof(int));


    for (int i = 0; i < n; i++)
    {
        scanf("%d", arr+i);
    }
    int count = 0;
    for (int i = 0; i < n -1 ; i++)
    {
        
        
        for (int j = 0; j < n -i - 1; j++)
        {
            if (*(arr+j) > *(arr+j+1))
            {
                int temp = *(arr+j);
                *(arr+j) = *(arr+j+1);
                *(arr+j+1) = temp;
                count ++;
            }
            
        }
       
        
    }
   
    printf("%d\n", count);
    free(arr);
    
    return 0;
}