/*-----------------Exercise 1-8 from the c programming language boook--------------------
                    Write a program to count blanks, tab, newline.
*/


#include <stdio.h>


int main() {
    int c, bla = 0, tab = 0, nl = 0;
    while ((c = getchar()) != EOF)
    {
        if (c == ' ') ++bla;
        else if (c == '\t') ++tab;
        else if (c == '\n') ++nl; 
    }
    
    printf("Blanks : %d \t Tab : %d \t Newline : %d \n", bla, tab, nl);
    return 0;
}