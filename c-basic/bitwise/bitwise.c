#include <stdio.h>

int main(void) {

	unsigned int a = 12;
	unsigned int b = 6;  
	unsigned int c = 0;  
	
	c = a&b;
	printf("4 should  %d\n", c);
	c = a|b;
	printf("14 should %d\n", c);
	c = a^b;
	printf("10 should %d\n", c);
	c = a<<1;
	printf("24 should %d\n", c);
	c = a>>1;
	printf("6 should %d\n", c);
	c = ~(a << 4) & b; 
	printf("6 should %d\n", c);
	c = c | (1<<4);
	printf("22 should %d\n", c);
	return 0;	
}
