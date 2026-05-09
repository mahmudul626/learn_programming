#include <stdio.h>
#include <stdint.h>

#define SIZE 64
#define CMD 32
volatile char buffer[SIZE];
uint8_t tail = 0;
uint8_t head = 0;

void enqueue(char data) {
	int next = (tail+1) % SIZE;
	if(next == head) {
		printf("buffer full\n");
		return;
	}

	buffer[tail] = data;
	tail = next;
}

char dequeue() {
	if(head == tail) {
		printf("buffer empty\n");
		return '\0';
	}

	char data = buffer[head];
	head = (head+1) % SIZE;
	return data;
}

int main() {
	char cmd[CMD];
	int ci = 0;
	while(1) {
		char input;
		scanf("%c", &input);
		enqueue(input);

		char c = dequeue();
		if(c == '\n') {
			cmd[ci] = '\0';
			ci = 0;
			printf("cmd : %s\n", cmd);
		} else if(ci < (CMD - 1)) {
			cmd[ci++] = c;
		}
	}
}
