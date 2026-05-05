#include <stdio.h>

int maximizingXor(int l, int r) {
    int max = 0;
    for(int i = l; i <= r; i++) {
        for (int j = i; j <= r; j++) {
            int value = i^j;
            if(max < value) {
                max = value;
            }
        }
    }
    return max;
}

int main() {
	int a,b;
	scanf("%d %d", &a, &b);
	int value = maximizingXor(a,b);
	printf("%d\n", value);
	return 0;
}

