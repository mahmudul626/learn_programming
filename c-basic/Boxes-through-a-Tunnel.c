/*
Problem Description:

You are transporting some boxes through a tunnel. Each box is a parallelepiped characterized by its length, width, and height.

The tunnel has infinite width and feet (length) but a fixed height. A box can be carried through the tunnel only if its height is strictly less than the tunnel's height. Boxes cannot be rotated.

Input Format:

- The first line contains a single integer N, denoting the number of boxes.
- The next N lines each contain three integers L, W, H separated by spaces, representing the length, width, and height of the i-th box.

Constraints:

- All box dimensions are positive integers.
- Boxes cannot be rotated; their orientation must remain as given.

Output Format:

- For every box whose height is strictly less than the tunnel's height, print its volume on a separate line.

Sample Input:

4
5 5 5
1 2 40
10 5 41
7 2 42

Sample Output:

125
80

Explanation:

- Box 1: height 5 < tunnel height → volume = 5*5*5 = 125 → printed
- Box 2: height 40 < tunnel height → volume = 1*2*40 = 80 → printed
- Box 3: height 41 = tunnel height → cannot pass → not printed
- Box 4: height 42 > tunnel height → cannot pass → not printed
*/

#include <stdio.h>
#include <stdlib.h>
#define MAX_HEIGHT 41

struct box
{
	/**
	* Define three fields of type int: length, width and height
	*/
    int length, width, height;
};

typedef struct box box;

int get_volume(box b) {
	/**
	* Return the volume of the box
	*/
    return b.length * b.width * b.height;
}

int is_lower_than_max_height(box b) {
	/**
	* Return 1 if the box's height is lower than MAX_HEIGHT and 0 otherwise
	*/
    if(b.height < MAX_HEIGHT) return 1;
    else return 0;
}

int main()
{
	int n;
	scanf("%d", &n);
	box *boxes = malloc(n * sizeof(box));
	for (int i = 0; i < n; i++) {
		scanf("%d%d%d", &boxes[i].length, &boxes[i].width, &boxes[i].height);
	}
	for (int i = 0; i < n; i++) {
		if (is_lower_than_max_height(boxes[i])) {
			printf("%d\n", get_volume(boxes[i]));
		}
	}
	return 0;
}