#include <stdio.h>

int main () {
    int num;
    scanf("%d", &num);

    for(int i = 0; i<num; i++) {
        int s = num - i - 1;
        for(int j = 0; j<s; j++) {
            printf(" ");
        }
        for(int x = 0; x <= i; x++) {
            printf("#");
        }
        printf("\n");
    }
    return 0;
}

