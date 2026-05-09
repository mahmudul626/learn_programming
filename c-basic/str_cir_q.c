#include <stdio.h>

#define SIZE 64
volatile char buffer[SIZE];
int head = 0;
int tail = 0;

void enqueue(char data) {
	if(tail == SIZE) printf("buffer full\n");
	buffer[tail] = data;
	tail = (tail+1) % SIZE;
}

char dequeue() {
	char data = buffer[head];
	head = (head+1) % SIZE;
	return data;
}

int main() {
	char c;

	while(1) {
		scanf("%c", &c);
		printf("\n");
		enqueue(c);
		printf("%c\n", dequeue());
	}
}

