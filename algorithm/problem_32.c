/**
 * Function to find the minimum distance between any pair of equal elements.
 * * Logic:
 * 1. Initialize 'dis' with the maximum possible integer value.
 * 2. Use a nested loop to compare each element at index 'i' with every 
 * subsequent element at index 'j'.
 * 3. If a match is found (a[i] == a[j]), calculate the absolute distance |i - j|.
 * 4. Update 'dis' if the newly calculated distance is smaller than the current 'dis'.
 * 5. If 'dis' remains unchanged (INT_MAX), it means no matching pair was found.
 * * Time Complexity: O(n^2) - suitable for n <= 1000.
 */
#include <limits.h>

 int minimumDistances(int a_count, int* a) {
    int dis = INT_MAX;
    for (int i = 0; i < a_count; i++) {
        
        for (int j = i + 1; j < a_count; j++) {
            if (*(a+i) == *(a+j)) {
                int min = abs(i-j);
                if (dis > min) {
                    dis = min;
                    
                }
                
            }
        }
    }
    if (dis == INT_MAX)
        return -1;

return  dis;
}