#include <stdio.h>
#include <stdint.h>

#define SIZE 3
volatile uint8_t arr[SIZE];
uint8_t front = 0;
uint8_t rear = 0;

void enqueue(int data) {
	int next = (rear + 1) % SIZE;
	arr[rear] = data;
	rear = next;
}

int dequeue() {
	int data = arr[front];
	front = (front + 1) % SIZE;
	return data;
}

int main() {
	int n;
	while(1) {
		scanf("%d", &n);
		enqueue(n);
		for(int i = 0; i<SIZE; i++) {
			printf("%d\n", arr[i]);
		}
	}
}
