/*
Problem Description:

You are given an array of integers called `marks`, which represents
the marks scored by students in a class.

The array follows a specific pattern:
- Elements at index 0, 2, 4, ... represent the marks of boys.
- Elements at index 1, 3, 5, ... represent the marks of girls.

The array name `marks` acts like a pointer, meaning it stores the base
memory address of the first element (marks[0]).

Your task is to compute the total marks based on gender.

Function:
int marks_summation(int* marks, int number_of_students, char gender);

Parameters:
- marks: pointer to the array of student marks
- number_of_students: total number of students (size of the array)
- gender: a character ('b' for boys, 'g' for girls)

Return:
- If gender == 'b', return the sum of marks at even indices (0, 2, 4, ...)
- If gender == 'g', return the sum of marks at odd indices (1, 3, 5, ...)

Input Format:
- First line: integer n (number of students)
- Next n lines: each line contains one integer (marks[i])
- Last line: a character ('b' or 'g')

Constraints:
- 1 ≤ n ≤ 1000
- marks[i] are valid integers
- gender is either 'b' or 'g'

Example:
marks = [3, 2, 5], gender = 'b'
Result = 3 + 5 = 8

marks = [1, 2, 3, 4, 5], gender = 'g'
Result = 2 + 4 = 6

Edge Case:
If no element exists for the selected gender (e.g., only one element and gender = 'g'),
then return 0.
*/

#include <stdio.h>
#include <stdlib.h>


int marks_summation(int* marks, int number_of_students, char gender) {

  int sum = 0;
  
  if (gender == 'b') {
    for(int i = 0; i < number_of_students; i++) {
        if(i % 2 == 0) {
            sum += marks[i];
        }
    }
  } else if (gender == 'g') {
    for(int i = 0; i < number_of_students; i++) {
        if(i % 2 != 0) {
            sum += marks[i];
        }
    }
  }
  return sum;
}

int main() {
    int num;
    char gen;
    printf("Enter Number : ");
    scanf("%d", &num);
    int *mark = (int *) malloc(num * sizeof(int));

    printf("Enter marks\n");
    for (int i = 0; i < num; i++)
    {
        scanf("%d", mark+i);
    }

    printf("Enter Gen : ");
    scanf(" %c", &gen);

    printf("Output : %d\n", marks_summation(mark, num, gen));

    return 0;
}